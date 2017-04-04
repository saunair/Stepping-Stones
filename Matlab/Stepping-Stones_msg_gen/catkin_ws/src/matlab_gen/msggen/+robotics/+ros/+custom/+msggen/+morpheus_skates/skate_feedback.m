classdef skate_feedback < robotics.ros.Message
    %skate_feedback MATLAB implementation of morpheus_skates/skate_feedback
    %   This class was automatically generated by
    %   robotics.ros.msg.internal.gen.MessageClassGenerator.
    
    %   Copyright 2017 The MathWorks, Inc.
    
    %#ok<*INUSD>
    
    properties (Constant)
        MessageType = 'morpheus_skates/skate_feedback' % The ROS message type
    end
    
    properties (Constant, Hidden)
        MD5Checksum = 'eb441f3c96e0f976c3b78a494f1af1b1' % The MD5 Checksum of the message definition
    end
    
    properties (Access = protected)
        JavaMessage % The Java message object
    end
    
    properties (Constant, Access = protected)
        StdMsgsHeaderClass = robotics.ros.msg.internal.MessageFactory.getClassForType('std_msgs/Header') % Dispatch to MATLAB class for message type std_msgs/Header
    end
    
    properties (Dependent)
        Header
        ForceFrontOuter
        ForceFrontInner
        ForceRear
        ImuQuatX
        ImuQuatY
        ImuQuatZ
        ImuQuatW
        ImuAccelX
        ImuAccelY
        ImuAccelZ
        ImuRateX
        ImuRateY
        ImuRateZ
        VelocityCmdRear
        VelocityCmdFront
        SkateFault
        PositionFiltRear
        PositionFiltFront
        VelocityFiltRear
        VelocityFiltFront
        DeadManEnable
        ControllerTargetRear
        ControllerTargetFront
        SkateMode
        DebugInt1
        DebugInt2
        DebugInt3
        DebugInt4
        DebugFloat1
        DebugFloat2
    end
    
    properties (Access = protected)
        Cache = struct('Header', []) % The cache for fast data access
    end
    
    properties (Constant, Hidden)
        PropertyList = {'ControllerTargetFront', 'ControllerTargetRear', 'DeadManEnable', 'DebugFloat1', 'DebugFloat2', 'DebugInt1', 'DebugInt2', 'DebugInt3', 'DebugInt4', 'ForceFrontInner', 'ForceFrontOuter', 'ForceRear', 'Header', 'ImuAccelX', 'ImuAccelY', 'ImuAccelZ', 'ImuQuatW', 'ImuQuatX', 'ImuQuatY', 'ImuQuatZ', 'ImuRateX', 'ImuRateY', 'ImuRateZ', 'PositionFiltFront', 'PositionFiltRear', 'SkateFault', 'SkateMode', 'VelocityCmdFront', 'VelocityCmdRear', 'VelocityFiltFront', 'VelocityFiltRear'} % List of non-constant message properties
        ROSPropertyList = {'controller_target_front', 'controller_target_rear', 'dead_man_enable', 'debug_float1', 'debug_float2', 'debug_int1', 'debug_int2', 'debug_int3', 'debug_int4', 'force_front_inner', 'force_front_outer', 'force_rear', 'header', 'imu_accel_x', 'imu_accel_y', 'imu_accel_z', 'imu_quat_w', 'imu_quat_x', 'imu_quat_y', 'imu_quat_z', 'imu_rate_x', 'imu_rate_y', 'imu_rate_z', 'position_filt_front', 'position_filt_rear', 'skate_fault', 'skate_mode', 'velocity_cmd_front', 'velocity_cmd_rear', 'velocity_filt_front', 'velocity_filt_rear'} % List of non-constant ROS message properties
    end
    
    methods
        function obj = skate_feedback(msg)
            %skate_feedback Construct the message object skate_feedback
            import com.mathworks.toolbox.robotics.ros.message.MessageInfo;
            
            % Support default constructor
            if nargin == 0
                obj.JavaMessage = obj.createNewJavaMessage;
                return;
            end
            
            % Construct appropriate empty array
            if isempty(msg)
                obj = obj.empty(0,1);
                return;
            end
            
            % Make scalar construction fast
            if isscalar(msg)
                % Check for correct input class
                if ~MessageInfo.compareTypes(msg(1), obj.MessageType)
                    error(message('robotics:ros:message:NoTypeMatch', obj.MessageType, ...
                        char(MessageInfo.getType(msg(1))) ));
                end
                obj.JavaMessage = msg(1);
                return;
            end
            
            % Check that this is a vector of scalar messages. Since this
            % is an object array, use arrayfun to verify.
            if ~all(arrayfun(@isscalar, msg))
                error(message('robotics:ros:message:MessageArraySizeError'));
            end
            
            % Check that all messages in the array have the correct type
            if ~all(arrayfun(@(x) MessageInfo.compareTypes(x, obj.MessageType), msg))
                error(message('robotics:ros:message:NoTypeMatchArray', obj.MessageType));
            end
            
            % Construct array of objects if necessary
            objType = class(obj);
            for i = 1:length(msg)
                obj(i,1) = feval(objType, msg(i)); %#ok<AGROW>
            end
        end
        
        function header = get.Header(obj)
            %get.Header Get the value for property Header
            if isempty(obj.Cache.Header)
                obj.Cache.Header = feval(obj.StdMsgsHeaderClass, obj.JavaMessage.getHeader);
            end
            header = obj.Cache.Header;
        end
        
        function set.Header(obj, header)
            %set.Header Set the value for property Header
            validateattributes(header, {obj.StdMsgsHeaderClass}, {'nonempty', 'scalar'}, 'skate_feedback', 'Header');
            
            obj.JavaMessage.setHeader(header.getJavaObject);
            
            % Update cache if necessary
            if ~isempty(obj.Cache.Header)
                obj.Cache.Header.setJavaObject(header.getJavaObject);
            end
        end
        
        function forcefrontouter = get.ForceFrontOuter(obj)
            %get.ForceFrontOuter Get the value for property ForceFrontOuter
            forcefrontouter = int16(obj.JavaMessage.getForceFrontOuter);
        end
        
        function set.ForceFrontOuter(obj, forcefrontouter)
            %set.ForceFrontOuter Set the value for property ForceFrontOuter
            validateattributes(forcefrontouter, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ForceFrontOuter');
            
            obj.JavaMessage.setForceFrontOuter(forcefrontouter);
        end
        
        function forcefrontinner = get.ForceFrontInner(obj)
            %get.ForceFrontInner Get the value for property ForceFrontInner
            forcefrontinner = int16(obj.JavaMessage.getForceFrontInner);
        end
        
        function set.ForceFrontInner(obj, forcefrontinner)
            %set.ForceFrontInner Set the value for property ForceFrontInner
            validateattributes(forcefrontinner, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ForceFrontInner');
            
            obj.JavaMessage.setForceFrontInner(forcefrontinner);
        end
        
        function forcerear = get.ForceRear(obj)
            %get.ForceRear Get the value for property ForceRear
            forcerear = int16(obj.JavaMessage.getForceRear);
        end
        
        function set.ForceRear(obj, forcerear)
            %set.ForceRear Set the value for property ForceRear
            validateattributes(forcerear, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ForceRear');
            
            obj.JavaMessage.setForceRear(forcerear);
        end
        
        function imuquatx = get.ImuQuatX(obj)
            %get.ImuQuatX Get the value for property ImuQuatX
            imuquatx = int16(obj.JavaMessage.getImuQuatX);
        end
        
        function set.ImuQuatX(obj, imuquatx)
            %set.ImuQuatX Set the value for property ImuQuatX
            validateattributes(imuquatx, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ImuQuatX');
            
            obj.JavaMessage.setImuQuatX(imuquatx);
        end
        
        function imuquaty = get.ImuQuatY(obj)
            %get.ImuQuatY Get the value for property ImuQuatY
            imuquaty = int16(obj.JavaMessage.getImuQuatY);
        end
        
        function set.ImuQuatY(obj, imuquaty)
            %set.ImuQuatY Set the value for property ImuQuatY
            validateattributes(imuquaty, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ImuQuatY');
            
            obj.JavaMessage.setImuQuatY(imuquaty);
        end
        
        function imuquatz = get.ImuQuatZ(obj)
            %get.ImuQuatZ Get the value for property ImuQuatZ
            imuquatz = int16(obj.JavaMessage.getImuQuatZ);
        end
        
        function set.ImuQuatZ(obj, imuquatz)
            %set.ImuQuatZ Set the value for property ImuQuatZ
            validateattributes(imuquatz, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ImuQuatZ');
            
            obj.JavaMessage.setImuQuatZ(imuquatz);
        end
        
        function imuquatw = get.ImuQuatW(obj)
            %get.ImuQuatW Get the value for property ImuQuatW
            imuquatw = int16(obj.JavaMessage.getImuQuatW);
        end
        
        function set.ImuQuatW(obj, imuquatw)
            %set.ImuQuatW Set the value for property ImuQuatW
            validateattributes(imuquatw, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ImuQuatW');
            
            obj.JavaMessage.setImuQuatW(imuquatw);
        end
        
        function imuaccelx = get.ImuAccelX(obj)
            %get.ImuAccelX Get the value for property ImuAccelX
            imuaccelx = single(obj.JavaMessage.getImuAccelX);
        end
        
        function set.ImuAccelX(obj, imuaccelx)
            %set.ImuAccelX Set the value for property ImuAccelX
            validateattributes(imuaccelx, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ImuAccelX');
            
            obj.JavaMessage.setImuAccelX(imuaccelx);
        end
        
        function imuaccely = get.ImuAccelY(obj)
            %get.ImuAccelY Get the value for property ImuAccelY
            imuaccely = single(obj.JavaMessage.getImuAccelY);
        end
        
        function set.ImuAccelY(obj, imuaccely)
            %set.ImuAccelY Set the value for property ImuAccelY
            validateattributes(imuaccely, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ImuAccelY');
            
            obj.JavaMessage.setImuAccelY(imuaccely);
        end
        
        function imuaccelz = get.ImuAccelZ(obj)
            %get.ImuAccelZ Get the value for property ImuAccelZ
            imuaccelz = single(obj.JavaMessage.getImuAccelZ);
        end
        
        function set.ImuAccelZ(obj, imuaccelz)
            %set.ImuAccelZ Set the value for property ImuAccelZ
            validateattributes(imuaccelz, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ImuAccelZ');
            
            obj.JavaMessage.setImuAccelZ(imuaccelz);
        end
        
        function imuratex = get.ImuRateX(obj)
            %get.ImuRateX Get the value for property ImuRateX
            imuratex = single(obj.JavaMessage.getImuRateX);
        end
        
        function set.ImuRateX(obj, imuratex)
            %set.ImuRateX Set the value for property ImuRateX
            validateattributes(imuratex, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ImuRateX');
            
            obj.JavaMessage.setImuRateX(imuratex);
        end
        
        function imuratey = get.ImuRateY(obj)
            %get.ImuRateY Get the value for property ImuRateY
            imuratey = single(obj.JavaMessage.getImuRateY);
        end
        
        function set.ImuRateY(obj, imuratey)
            %set.ImuRateY Set the value for property ImuRateY
            validateattributes(imuratey, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ImuRateY');
            
            obj.JavaMessage.setImuRateY(imuratey);
        end
        
        function imuratez = get.ImuRateZ(obj)
            %get.ImuRateZ Get the value for property ImuRateZ
            imuratez = single(obj.JavaMessage.getImuRateZ);
        end
        
        function set.ImuRateZ(obj, imuratez)
            %set.ImuRateZ Set the value for property ImuRateZ
            validateattributes(imuratez, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ImuRateZ');
            
            obj.JavaMessage.setImuRateZ(imuratez);
        end
        
        function velocitycmdrear = get.VelocityCmdRear(obj)
            %get.VelocityCmdRear Get the value for property VelocityCmdRear
            velocitycmdrear = single(obj.JavaMessage.getVelocityCmdRear);
        end
        
        function set.VelocityCmdRear(obj, velocitycmdrear)
            %set.VelocityCmdRear Set the value for property VelocityCmdRear
            validateattributes(velocitycmdrear, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'VelocityCmdRear');
            
            obj.JavaMessage.setVelocityCmdRear(velocitycmdrear);
        end
        
        function velocitycmdfront = get.VelocityCmdFront(obj)
            %get.VelocityCmdFront Get the value for property VelocityCmdFront
            velocitycmdfront = single(obj.JavaMessage.getVelocityCmdFront);
        end
        
        function set.VelocityCmdFront(obj, velocitycmdfront)
            %set.VelocityCmdFront Set the value for property VelocityCmdFront
            validateattributes(velocitycmdfront, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'VelocityCmdFront');
            
            obj.JavaMessage.setVelocityCmdFront(velocitycmdfront);
        end
        
        function skatefault = get.SkateFault(obj)
            %get.SkateFault Get the value for property SkateFault
            skatefault = typecast(int8(obj.JavaMessage.getSkateFault), 'uint8');
        end
        
        function set.SkateFault(obj, skatefault)
            %set.SkateFault Set the value for property SkateFault
            validateattributes(skatefault, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'SkateFault');
            
            obj.JavaMessage.setSkateFault(skatefault);
        end
        
        function positionfiltrear = get.PositionFiltRear(obj)
            %get.PositionFiltRear Get the value for property PositionFiltRear
            positionfiltrear = single(obj.JavaMessage.getPositionFiltRear);
        end
        
        function set.PositionFiltRear(obj, positionfiltrear)
            %set.PositionFiltRear Set the value for property PositionFiltRear
            validateattributes(positionfiltrear, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'PositionFiltRear');
            
            obj.JavaMessage.setPositionFiltRear(positionfiltrear);
        end
        
        function positionfiltfront = get.PositionFiltFront(obj)
            %get.PositionFiltFront Get the value for property PositionFiltFront
            positionfiltfront = single(obj.JavaMessage.getPositionFiltFront);
        end
        
        function set.PositionFiltFront(obj, positionfiltfront)
            %set.PositionFiltFront Set the value for property PositionFiltFront
            validateattributes(positionfiltfront, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'PositionFiltFront');
            
            obj.JavaMessage.setPositionFiltFront(positionfiltfront);
        end
        
        function velocityfiltrear = get.VelocityFiltRear(obj)
            %get.VelocityFiltRear Get the value for property VelocityFiltRear
            velocityfiltrear = single(obj.JavaMessage.getVelocityFiltRear);
        end
        
        function set.VelocityFiltRear(obj, velocityfiltrear)
            %set.VelocityFiltRear Set the value for property VelocityFiltRear
            validateattributes(velocityfiltrear, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'VelocityFiltRear');
            
            obj.JavaMessage.setVelocityFiltRear(velocityfiltrear);
        end
        
        function velocityfiltfront = get.VelocityFiltFront(obj)
            %get.VelocityFiltFront Get the value for property VelocityFiltFront
            velocityfiltfront = single(obj.JavaMessage.getVelocityFiltFront);
        end
        
        function set.VelocityFiltFront(obj, velocityfiltfront)
            %set.VelocityFiltFront Set the value for property VelocityFiltFront
            validateattributes(velocityfiltfront, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'VelocityFiltFront');
            
            obj.JavaMessage.setVelocityFiltFront(velocityfiltfront);
        end
        
        function deadmanenable = get.DeadManEnable(obj)
            %get.DeadManEnable Get the value for property DeadManEnable
            deadmanenable = logical(obj.JavaMessage.getDeadManEnable);
        end
        
        function set.DeadManEnable(obj, deadmanenable)
            %set.DeadManEnable Set the value for property DeadManEnable
            validateattributes(deadmanenable, {'logical', 'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'DeadManEnable');
            
            obj.JavaMessage.setDeadManEnable(deadmanenable);
        end
        
        function controllertargetrear = get.ControllerTargetRear(obj)
            %get.ControllerTargetRear Get the value for property ControllerTargetRear
            controllertargetrear = single(obj.JavaMessage.getControllerTargetRear);
        end
        
        function set.ControllerTargetRear(obj, controllertargetrear)
            %set.ControllerTargetRear Set the value for property ControllerTargetRear
            validateattributes(controllertargetrear, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ControllerTargetRear');
            
            obj.JavaMessage.setControllerTargetRear(controllertargetrear);
        end
        
        function controllertargetfront = get.ControllerTargetFront(obj)
            %get.ControllerTargetFront Get the value for property ControllerTargetFront
            controllertargetfront = single(obj.JavaMessage.getControllerTargetFront);
        end
        
        function set.ControllerTargetFront(obj, controllertargetfront)
            %set.ControllerTargetFront Set the value for property ControllerTargetFront
            validateattributes(controllertargetfront, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'ControllerTargetFront');
            
            obj.JavaMessage.setControllerTargetFront(controllertargetfront);
        end
        
        function skatemode = get.SkateMode(obj)
            %get.SkateMode Get the value for property SkateMode
            skatemode = typecast(int8(obj.JavaMessage.getSkateMode), 'uint8');
        end
        
        function set.SkateMode(obj, skatemode)
            %set.SkateMode Set the value for property SkateMode
            validateattributes(skatemode, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'SkateMode');
            
            obj.JavaMessage.setSkateMode(skatemode);
        end
        
        function debugint1 = get.DebugInt1(obj)
            %get.DebugInt1 Get the value for property DebugInt1
            debugint1 = int16(obj.JavaMessage.getDebugInt1);
        end
        
        function set.DebugInt1(obj, debugint1)
            %set.DebugInt1 Set the value for property DebugInt1
            validateattributes(debugint1, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'DebugInt1');
            
            obj.JavaMessage.setDebugInt1(debugint1);
        end
        
        function debugint2 = get.DebugInt2(obj)
            %get.DebugInt2 Get the value for property DebugInt2
            debugint2 = int16(obj.JavaMessage.getDebugInt2);
        end
        
        function set.DebugInt2(obj, debugint2)
            %set.DebugInt2 Set the value for property DebugInt2
            validateattributes(debugint2, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'DebugInt2');
            
            obj.JavaMessage.setDebugInt2(debugint2);
        end
        
        function debugint3 = get.DebugInt3(obj)
            %get.DebugInt3 Get the value for property DebugInt3
            debugint3 = int16(obj.JavaMessage.getDebugInt3);
        end
        
        function set.DebugInt3(obj, debugint3)
            %set.DebugInt3 Set the value for property DebugInt3
            validateattributes(debugint3, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'DebugInt3');
            
            obj.JavaMessage.setDebugInt3(debugint3);
        end
        
        function debugint4 = get.DebugInt4(obj)
            %get.DebugInt4 Get the value for property DebugInt4
            debugint4 = int16(obj.JavaMessage.getDebugInt4);
        end
        
        function set.DebugInt4(obj, debugint4)
            %set.DebugInt4 Set the value for property DebugInt4
            validateattributes(debugint4, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'DebugInt4');
            
            obj.JavaMessage.setDebugInt4(debugint4);
        end
        
        function debugfloat1 = get.DebugFloat1(obj)
            %get.DebugFloat1 Get the value for property DebugFloat1
            debugfloat1 = single(obj.JavaMessage.getDebugFloat1);
        end
        
        function set.DebugFloat1(obj, debugfloat1)
            %set.DebugFloat1 Set the value for property DebugFloat1
            validateattributes(debugfloat1, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'DebugFloat1');
            
            obj.JavaMessage.setDebugFloat1(debugfloat1);
        end
        
        function debugfloat2 = get.DebugFloat2(obj)
            %get.DebugFloat2 Get the value for property DebugFloat2
            debugfloat2 = single(obj.JavaMessage.getDebugFloat2);
        end
        
        function set.DebugFloat2(obj, debugfloat2)
            %set.DebugFloat2 Set the value for property DebugFloat2
            validateattributes(debugfloat2, {'numeric'}, {'nonempty', 'scalar'}, 'skate_feedback', 'DebugFloat2');
            
            obj.JavaMessage.setDebugFloat2(debugfloat2);
        end
    end
    
    methods (Access = protected)
        function resetCache(obj)
            %resetCache Resets any cached properties
            obj.Cache.Header = [];
        end
        
        function cpObj = copyElement(obj)
            %copyElement Implements deep copy behavior for message
            
            % Call default copy method for shallow copy
            cpObj = copyElement@robotics.ros.Message(obj);
            
            % Clear any existing cached properties
            cpObj.resetCache;
            
            % Create a new Java message object
            cpObj.JavaMessage = obj.createNewJavaMessage;
            
            % Iterate over all primitive properties
            cpObj.ForceFrontOuter = obj.ForceFrontOuter;
            cpObj.ForceFrontInner = obj.ForceFrontInner;
            cpObj.ForceRear = obj.ForceRear;
            cpObj.ImuQuatX = obj.ImuQuatX;
            cpObj.ImuQuatY = obj.ImuQuatY;
            cpObj.ImuQuatZ = obj.ImuQuatZ;
            cpObj.ImuQuatW = obj.ImuQuatW;
            cpObj.ImuAccelX = obj.ImuAccelX;
            cpObj.ImuAccelY = obj.ImuAccelY;
            cpObj.ImuAccelZ = obj.ImuAccelZ;
            cpObj.ImuRateX = obj.ImuRateX;
            cpObj.ImuRateY = obj.ImuRateY;
            cpObj.ImuRateZ = obj.ImuRateZ;
            cpObj.VelocityCmdRear = obj.VelocityCmdRear;
            cpObj.VelocityCmdFront = obj.VelocityCmdFront;
            cpObj.SkateFault = obj.SkateFault;
            cpObj.PositionFiltRear = obj.PositionFiltRear;
            cpObj.PositionFiltFront = obj.PositionFiltFront;
            cpObj.VelocityFiltRear = obj.VelocityFiltRear;
            cpObj.VelocityFiltFront = obj.VelocityFiltFront;
            cpObj.DeadManEnable = obj.DeadManEnable;
            cpObj.ControllerTargetRear = obj.ControllerTargetRear;
            cpObj.ControllerTargetFront = obj.ControllerTargetFront;
            cpObj.SkateMode = obj.SkateMode;
            cpObj.DebugInt1 = obj.DebugInt1;
            cpObj.DebugInt2 = obj.DebugInt2;
            cpObj.DebugInt3 = obj.DebugInt3;
            cpObj.DebugInt4 = obj.DebugInt4;
            cpObj.DebugFloat1 = obj.DebugFloat1;
            cpObj.DebugFloat2 = obj.DebugFloat2;
            
            % Recursively copy compound properties
            cpObj.Header = copy(obj.Header);
        end
        
        function reload(obj, strObj)
            %reload Called by loadobj to assign properties
            obj.ForceFrontOuter = strObj.ForceFrontOuter;
            obj.ForceFrontInner = strObj.ForceFrontInner;
            obj.ForceRear = strObj.ForceRear;
            obj.ImuQuatX = strObj.ImuQuatX;
            obj.ImuQuatY = strObj.ImuQuatY;
            obj.ImuQuatZ = strObj.ImuQuatZ;
            obj.ImuQuatW = strObj.ImuQuatW;
            obj.ImuAccelX = strObj.ImuAccelX;
            obj.ImuAccelY = strObj.ImuAccelY;
            obj.ImuAccelZ = strObj.ImuAccelZ;
            obj.ImuRateX = strObj.ImuRateX;
            obj.ImuRateY = strObj.ImuRateY;
            obj.ImuRateZ = strObj.ImuRateZ;
            obj.VelocityCmdRear = strObj.VelocityCmdRear;
            obj.VelocityCmdFront = strObj.VelocityCmdFront;
            obj.SkateFault = strObj.SkateFault;
            obj.PositionFiltRear = strObj.PositionFiltRear;
            obj.PositionFiltFront = strObj.PositionFiltFront;
            obj.VelocityFiltRear = strObj.VelocityFiltRear;
            obj.VelocityFiltFront = strObj.VelocityFiltFront;
            obj.DeadManEnable = strObj.DeadManEnable;
            obj.ControllerTargetRear = strObj.ControllerTargetRear;
            obj.ControllerTargetFront = strObj.ControllerTargetFront;
            obj.SkateMode = strObj.SkateMode;
            obj.DebugInt1 = strObj.DebugInt1;
            obj.DebugInt2 = strObj.DebugInt2;
            obj.DebugInt3 = strObj.DebugInt3;
            obj.DebugInt4 = strObj.DebugInt4;
            obj.DebugFloat1 = strObj.DebugFloat1;
            obj.DebugFloat2 = strObj.DebugFloat2;
            obj.Header = feval([obj.StdMsgsHeaderClass '.loadobj'], strObj.Header);
        end
    end
    
    methods (Access = ?robotics.ros.Message)
        function strObj = saveobj(obj)
            %saveobj Implements saving of message to MAT file
            
            % Return an empty element if object array is empty
            if isempty(obj)
                strObj = struct.empty;
                return
            end
            
            strObj.ForceFrontOuter = obj.ForceFrontOuter;
            strObj.ForceFrontInner = obj.ForceFrontInner;
            strObj.ForceRear = obj.ForceRear;
            strObj.ImuQuatX = obj.ImuQuatX;
            strObj.ImuQuatY = obj.ImuQuatY;
            strObj.ImuQuatZ = obj.ImuQuatZ;
            strObj.ImuQuatW = obj.ImuQuatW;
            strObj.ImuAccelX = obj.ImuAccelX;
            strObj.ImuAccelY = obj.ImuAccelY;
            strObj.ImuAccelZ = obj.ImuAccelZ;
            strObj.ImuRateX = obj.ImuRateX;
            strObj.ImuRateY = obj.ImuRateY;
            strObj.ImuRateZ = obj.ImuRateZ;
            strObj.VelocityCmdRear = obj.VelocityCmdRear;
            strObj.VelocityCmdFront = obj.VelocityCmdFront;
            strObj.SkateFault = obj.SkateFault;
            strObj.PositionFiltRear = obj.PositionFiltRear;
            strObj.PositionFiltFront = obj.PositionFiltFront;
            strObj.VelocityFiltRear = obj.VelocityFiltRear;
            strObj.VelocityFiltFront = obj.VelocityFiltFront;
            strObj.DeadManEnable = obj.DeadManEnable;
            strObj.ControllerTargetRear = obj.ControllerTargetRear;
            strObj.ControllerTargetFront = obj.ControllerTargetFront;
            strObj.SkateMode = obj.SkateMode;
            strObj.DebugInt1 = obj.DebugInt1;
            strObj.DebugInt2 = obj.DebugInt2;
            strObj.DebugInt3 = obj.DebugInt3;
            strObj.DebugInt4 = obj.DebugInt4;
            strObj.DebugFloat1 = obj.DebugFloat1;
            strObj.DebugFloat2 = obj.DebugFloat2;
            strObj.Header = saveobj(obj.Header);
        end
    end
    
    methods (Static, Access = {?matlab.unittest.TestCase, ?robotics.ros.Message})
        function obj = loadobj(strObj)
            %loadobj Implements loading of message from MAT file
            
            % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = robotics.ros.custom.msggen.morpheus_skates.skate_feedback.empty(0,1);
                return
            end
            
            % Create an empty message object
            obj = robotics.ros.custom.msggen.morpheus_skates.skate_feedback;
            obj.reload(strObj);
        end
    end
end
