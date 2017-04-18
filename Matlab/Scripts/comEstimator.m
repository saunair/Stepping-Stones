function [comPosn,comPosnL,comPosnR] = comEstimator(bagTable)
    rows = size(bagTable,1);
    comPosn = zeros(rows,1);
    comPosnL = zeros(rows,1);
    comPosnR = zeros(rows,1);
    leftFrontSync = 0;
    leftFrontSyncPosn = 0;
    leftRearSync = 0;
    leftRearSyncPosn = 0;
    rightFrontSync = 0;
    rightFrontSyncPosn = 0;
    rightRearSync = 0;
    rightRearSyncPosn = 0;
    rise_t = 0.4;
    fall_t = 0.3;
    
    for idx = 1:rows
        %Determine Kinect foot front position
        %Sync to Kinect position at each heel strike
        %Use delta encoder position until toe off
        leftFrontKinPosn = bagTable.FootLeft_X(idx) - 7.5;
        leftFrontForce = bagTable.NormalizedForce_LeftNormalFrontInner(idx) + ...
           bagTable.NormalizedForce_LeftNormalFrontOuter(idx);
        if((leftFrontForce > rise_t) && (leftFrontSync == 0))
            leftFrontSyncPosn = leftFrontKinPosn;
            leftFrontPosn = leftFrontSyncPosn;
            leftFrontEncOff = bagTable.LeftFeedback_PositionFiltFront;
            leftFrontSync = 1; 
        else
            if(leftFrontForce < fall_t)
                leftFrontPosn = leftFrontKinPosn;
                leftFrontSync = 0;
            else
                leftFrontPosn = 
               
           
        leftFrontTorque = leftFrontPosn * leftFrontForce;
        
        leftRearPosn = bagTable.FootLeft_X(idx) + 1.5;
        leftRearForce = bagTable.NormalizedForce_LeftNormalRear(idx);
        leftRearTorque = leftRearPosn*leftRearForce;
        
        comPosnL(idx) = (leftFrontTorque + leftRearTorque) / ...
            bagTable.NormalizedForce_LeftNormalTotal(idx);
        
        rightFrontPosn = bagTable.FootRight_X(idx) - 7.5;
        rightFrontForce = bagTable.NormalizedForce_RightNormalFrontInner(idx) + ...
            bagTable.NormalizedForce_RightNormalFrontOuter(idx);
        rightFrontTorque = rightFrontPosn * rightFrontForce;
        
        rightRearPosn = bagTable.FootRight_X(idx) + 1.5;
        rightRearForce = bagTable.NormalizedForce_RightNormalRear(idx);      
        rightRearTorque = rightRearPosn*rightRearForce;
        
        comPosnR(idx) = (rightFrontTorque + rightRearTorque) / ...
            bagTable.NormalizedForce_RightNormalTotal(idx);
        
        comPosn(idx) = (leftFrontTorque + leftRearTorque + ...
            rightFrontTorque + rightRearTorque) / ...
            bagTable.NormalizedForce_NormalTotal(idx);
    end
end