#include "stdafx.h"
#include <string>
#include <stdio.h>
#include "ros.h"
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <windows.h>
#include <iostream>
#include <fstream>

#define WINVER 0x0500

using namespace std;

#define TOP_VELOCITY 300
#define DISCRETE_STEPS 5

// This structure will be used to create the keyboard input event.
INPUT ip;

void str_callback(const std_msgs::Float32 & num)
{
	printf("Received number %d\n", num.data);
	int discreteSpeed = 0;
	discreteSpeed = max(DISCRETE_STEPS, int((num.data / TOP_VELOCITY)*DISCRETE_STEPS));
	
	switch (discreteSpeed)
	{
	case 0:
		ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
		// Release the "Q" key
		ip.ki.wVk = 0x51;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "W" key
		ip.ki.wVk = 0x57;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "E" key
		ip.ki.wVk = 0x45;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "R" key
		ip.ki.wVk = 0x52;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "T" key
		ip.ki.wVk = 0x54;
		SendInput(1, &ip, sizeof(INPUT));
		printf("Standing still\n");
		break;
	case 1:
		ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
		// Release the "W" key
		ip.ki.wVk = 0x57;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "E" key
		ip.ki.wVk = 0x45;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "R" key
		ip.ki.wVk = 0x52;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "T" key
		ip.ki.wVk = 0x54;
		SendInput(1, &ip, sizeof(INPUT));
		// Press the "Q" key
		ip.ki.wVk = 0x51;
		ip.ki.dwFlags = 0;
		SendInput(1, &ip, sizeof(INPUT));
		printf("Pressing Q\n");
		break;
	case 2:
		ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
		// Release the "Q" key
		ip.ki.wVk = 0x51;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "E" key
		ip.ki.wVk = 0x45;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "R" key
		ip.ki.wVk = 0x52;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "T" key
		ip.ki.wVk = 0x54;
		SendInput(1, &ip, sizeof(INPUT));
		// Press the "W" key
		ip.ki.wVk = 0x57;
		ip.ki.dwFlags = 0;
		SendInput(1, &ip, sizeof(INPUT));
		printf("Pressing W\n");
		break;
	case 3:
		ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
		// Release the "Q" key
		ip.ki.wVk = 0x51;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "W" key
		ip.ki.wVk = 0x57;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "R" key
		ip.ki.wVk = 0x52;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "T" key
		ip.ki.wVk = 0x54;
		SendInput(1, &ip, sizeof(INPUT));
		// Press the "E" key
		ip.ki.wVk = 0x45;
		ip.ki.dwFlags = 0;
		SendInput(1, &ip, sizeof(INPUT));
		printf("Pressing E\n");
		break;
	case 4:
		ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
		// Release the "Q" key
		ip.ki.wVk = 0x51;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "W" key
		ip.ki.wVk = 0x57;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "E" key
		ip.ki.wVk = 0x45;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "T" key
		ip.ki.wVk = 0x54;
		SendInput(1, &ip, sizeof(INPUT));
		// Press the "R" key
		ip.ki.wVk = 0x52;
		ip.ki.dwFlags = 0;
		SendInput(1, &ip, sizeof(INPUT));
		printf("Pressing R\n");
		break;
	case 5:
		ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
		// Release the "Q" key
		ip.ki.wVk = 0x51;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "W" key
		ip.ki.wVk = 0x57;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "E" key
		ip.ki.wVk = 0x45;
		SendInput(1, &ip, sizeof(INPUT));
		// Release the "R" key
		ip.ki.wVk = 0x52;
		SendInput(1, &ip, sizeof(INPUT));
		// Press the "T" key
		ip.ki.wVk = 0x54;
		ip.ki.dwFlags = 0;
		SendInput(1, &ip, sizeof(INPUT));
		printf("Pressing T\n");
		break;
	}
}

int _tmain(int argc, _TCHAR * argv[])
{
	ros::NodeHandle nh;
	char *ros_master = "128.237.220.201";

	printf("Connecting to server at %s\n", ros_master);
	nh.initNode(ros_master);

	ros::Subscriber < std_msgs::Float32 > numSub("walking_speed", &str_callback);
	nh.subscribe(numSub);

	// Set up a generic keyboard event.
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	printf("Waiting to receive messages\n");
	while (1)
	{
		nh.spinOnce();
	}

	// Release all keys
	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	ip.ki.wVk = 0x51;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.wVk = 0x57;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.wVk = 0x45;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.wVk = 0x52;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.wVk = 0x54;
	SendInput(1, &ip, sizeof(INPUT));

	printf("All done!\n");

	return 0;
}