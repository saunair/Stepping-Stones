function plotRosbag(filename)
    bag = rosbag(filename);
    left = select(bag,'Topic','/left');
    servo = select(bag,'Topic','/servo'); 
    user_inputs = select(bag,'Topic','/user_inputs');
    
    
    force_front_outer = timeseries(left,'ForceFrontOuter');
	force_front_inner = timeseries(left,'ForceFrontInner');
	force_rear = timeseries(left,'ForceRear');
    figure();
    subplot(3,1,1); plot(force_front_outer); title('Force Sensors');
    subplot(3,1,2); plot(force_front_inner);
    subplot(3,1,3); plot(force_rear);
    
	imu_quat_x = timeseries(left,'ImuQuatX');
	imu_quat_y = timeseries(left,'ImuQuatY');
	imu_quat_z = timeseries(left,'ImuQuatZ');
	imu_quat_w = timeseries(left,'ImuQuatW');
    figure();
    subplot(4,1,1); plot(imu_quat_x); title('IMU Quaternions');
    subplot(4,1,2); plot(imu_quat_y);
    subplot(4,1,3); plot(imu_quat_z);
    subplot(4,1,4); plot(imu_quat_w);
    
	imu_accel_x = timeseries(left,'ImuAccelX');
	imu_accel_y = timeseries(left,'ImuAccelY');
	imu_accel_z = timeseries(left,'ImuAccelZ');
    figure();
    subplot(3,1,1); plot(imu_accel_x); title('IMU Acceleration');
    subplot(3,1,2); plot(imu_accel_y);
    subplot(3,1,3); plot(imu_accel_z);
    
	imu_rate_x = timeseries(left,'ImuRateX');
	imu_rate_y  = timeseries(left,'ImuRateY');
	imu_rate_z = timeseries(left,'ImuRateZ');
    figure();
    subplot(3,1,1); plot(imu_rate_x); title('IMU Ang Rates');
    subplot(3,1,2); plot(imu_rate_y);
    subplot(3,1,3); plot(imu_rate_z);
    
	velocity_cmd_rear = timeseries(left,'VelocityCmdRear');
	velocity_cmd_front = timeseries(left,'VelocityCmdFront');
    controller_target = timeseries(left,'ControllerTarget'); 
    figure();
    subplot(3,1,1); plot(velocity_cmd_rear); title('Velocity Commands/Tgt');
    subplot(3,1,2); plot(velocity_cmd_front);
    subplot(3,1,3); plot(controller_target);
    
	position_filt_rear = timeseries(left,'PositionFiltRear');
	position_filt_front = timeseries(left,'PositionFiltFront');
	velocity_filt_rear = timeseries(left,'VelocityFiltRear');
	velocity_filt_front = timeseries(left,'VelocityFiltRear');
    figure();
    subplot(4,1,1); plot(position_filt_rear); title('Position/Velocity');
    subplot(4,1,2); plot(position_filt_front);
    subplot(4,1,3); plot(velocity_filt_rear);
    subplot(4,1,4); plot(velocity_filt_front);
	  
    %dead_man_enable = timeseries(left,'DeadManEnable');
	skate_fault = timeseries(left,'SkateFault');
	skate_mode = timeseries(left,'SkateMode');
    figure();
    %subplot(3,1,1); plot(dead_man_enable); title('Enable/Fault/Mode');
    subplot(2,1,1); plot(skate_fault); title('Fault/Mode');
    subplot(2,1,2); plot(skate_mode);
    
    
    calibration_enable = timeseries(servo,'CalibrationEnable');
    command_target = timeseries(servo,'CommandTarget');
    figure();
    subplot(2,1,1); plot(calibration_enable); title('Calib/Target');
    subplot(2,1,2); plot(command_target);
    
    save(strcat(filename(1:end-4),'.mat'));
end