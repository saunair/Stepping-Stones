#include "UM.h"

//UM7
#define DREG_EULER_PHI_THETA 0x70	// Packet address sent from the UM7 that contains roll,pitch,yaw and rates.
#define DREG_ACCEL_PROC_X  0x65		//Packet address sent from the UM7 that contains processed accel_x data.
#define DREG_ACCEL_PROC_Y  0x66		//Packet address sent from the UM7 that contains processed accel_y data.
#define DREG_ACCEL_PROC_Z  0x67		//Packet address sent from the UM7 that contains processed accel_z data.
#define DREG_QUAT_AB	   0x6D		//Packet address sent from the UM7 that contains quaternion vector elements 1 and 2; use as a pointer for 3 and 4
#define DREG_GYRO_PROC_X   0x61		// angular rates	

/*//UM6
#define DREG_ACCEL_PROC_X 0x5E
#define DREG_QUAT_AB 0x64
#define DREG_GYRO_PROC_X  0x5C*/

UM::UM() : state(STATE_ZERO){}		// Default constructor


typedef union {
 byte array[4];
 float value;
} ByteToFloat;

float convert(byte* data) {
 ByteToFloat converter;
 for (byte i = 0; i < 4; i++){
   converter.array[3-i] = data[i]; //or converter.array[i] = data[i]; depending on endianness
 }
 return converter.value;
}

bool UM::encode(byte c){
	
	switch(state){
	case STATE_ZERO:
		if (c == 's'){
			state = STATE_S;		// Entering state S from state Zero
		} else {
			state = STATE_ZERO;
		}
		return false;
	case STATE_S:
		if (c == 'n'){
			state = STATE_SN;		// Entering state SN from state S
		} else {
			state = STATE_ZERO;
		}
		return false;
	case STATE_SN:
		if (c == 'p'){
			state = STATE_SNP;		// Entering state SNP from state SN.  Packet header detected.
		} else {
			state = STATE_ZERO;
		}
		return false;
	case STATE_SNP:
		state = STATE_PT;			// Entering state PT from state SNP.  Decode packet type.
		packet_type = c;
		packet_has_data = (packet_type >> 7) & 0x01;
		packet_is_batch = (packet_type >> 6) & 0x01;
		batch_length    = (packet_type >> 2) & 0x0F;
		if (packet_has_data){
			if (packet_is_batch){
				data_length = 4 * batch_length;	// Each data packet is 4 bytes long
			} else {
				data_length = 4;
			}
		} else {
			data_length = 0;
		}  
		return false;
	case STATE_PT:
		state = STATE_DATA;		// Next state will be READ_DATA.  Save address to memory. (eg 0x70 for a DREG_EULER_PHI_THETA packet)
		address = c;
		data_index = 0;
		return false;
	case STATE_DATA:			//  Entering state READ_DATA.  Stay in state until all data is read.
		data[data_index] = c;
		data_index++;
		if (data_index >= data_length){
			state = STATE_CHK1;	//  Data read completed.  Next state will be CHK1
		}
		return false;
	case STATE_CHK1:			// Entering state CHK1.  Next state will be CHK0
		state = STATE_CHK0;
		checksum1 = c;
		return false;
	case STATE_CHK0: 				
		state = STATE_ZERO;		// Entering state CHK0.  Next state will be state Zero.
		checksum0 = c;
		return checksum();
	}
}

bool UM::checksum(){
	checksum10  = checksum1 << 8;	// Combine checksum1 and checksum0
	checksum10 |= checksum0;
	computed_checksum = 's' + 'n' + 'p' + packet_type + address;
	for (int i = 0; i < data_length; i++){
		computed_checksum += data[i];
	}
	if (checksum10 == computed_checksum){
		save();
		return true;
	} else {
		return false;
	}
}

void UM::save(){
	switch(address){
	case DREG_QUAT_AB :
    updates |= 1<<2;
		if(packet_is_batch){
			quatA = data[0] << 8;
			quatA |= data[1];
			quatx = quatA/29789.09091;
			quatB = data[2] << 8;
			quatB |= data[3];
			quaty = quatB/29789.09091;
			quatC = data[4] << 8;
			quatC |= data[5];
			quatz = quatC/29789.09091;
			quatD = data[6] << 8;
			quatD |= data[7];
			quatw = quatD/29789.09091;
		}
		break;
	case DREG_GYRO_PROC_X:
    updates |= 1<<1;
		if(packet_is_batch){
			gyro_x = convert(data);
			gyro_y = convert(data + 4);
			gyro_z = convert(data + 8);
		}
		break;
	case DREG_ACCEL_PROC_X :
    updates |= 1<<0;		
		if(packet_is_batch){
			accel_x = convert(data);
			accel_y = convert(data + 4);
			accel_z = convert(data + 8);
		}
	break;
	}
}
