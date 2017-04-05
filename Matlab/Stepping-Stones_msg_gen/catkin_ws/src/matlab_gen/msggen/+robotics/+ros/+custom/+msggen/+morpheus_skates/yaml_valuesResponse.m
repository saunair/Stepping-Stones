classdef yaml_valuesResponse < robotics.ros.Message
    %yaml_valuesResponse MATLAB implementation of morpheus_skates/yaml_valuesResponse
    %   This class was automatically generated by
    %   robotics.ros.msg.internal.gen.MessageClassGenerator.
    
    %   Copyright 2017 The MathWorks, Inc.
    
    %#ok<*INUSD>
    
    properties (Constant)
        MessageType = 'morpheus_skates/yaml_valuesResponse' % The ROS message type
    end
    
    properties (Constant, Hidden)
        MD5Checksum = '599f443ae0f39cd3fc016639ad207690' % The MD5 Checksum of the message definition
    end
    
    properties (Access = protected)
        JavaMessage % The Java message object
    end
    
    properties (Dependent)
        LeftBiasF1
        LeftBiasF2
        LeftBiasF3
        LeftGainF1
        LeftGainF2
        LeftGainF3
        RightBiasF1
        RightBiasF2
        RightBiasF3
        RightGainF1
        RightGainF2
        RightGainF3
    end
    
    properties (Constant, Hidden)
        PropertyList = {'LeftBiasF1', 'LeftBiasF2', 'LeftBiasF3', 'LeftGainF1', 'LeftGainF2', 'LeftGainF3', 'RightBiasF1', 'RightBiasF2', 'RightBiasF3', 'RightGainF1', 'RightGainF2', 'RightGainF3'} % List of non-constant message properties
        ROSPropertyList = {'left_bias_f1', 'left_bias_f2', 'left_bias_f3', 'left_gain_f1', 'left_gain_f2', 'left_gain_f3', 'right_bias_f1', 'right_bias_f2', 'right_bias_f3', 'right_gain_f1', 'right_gain_f2', 'right_gain_f3'} % List of non-constant ROS message properties
    end
    
    methods
        function obj = yaml_valuesResponse(msg)
            %yaml_valuesResponse Construct the message object yaml_valuesResponse
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
        
        function leftbiasf1 = get.LeftBiasF1(obj)
            %get.LeftBiasF1 Get the value for property LeftBiasF1
            leftbiasf1 = double(obj.JavaMessage.getLeftBiasF1);
        end
        
        function set.LeftBiasF1(obj, leftbiasf1)
            %set.LeftBiasF1 Set the value for property LeftBiasF1
            validateattributes(leftbiasf1, {'numeric'}, {'nonempty', 'scalar'}, 'yaml_valuesResponse', 'LeftBiasF1');
            
            obj.JavaMessage.setLeftBiasF1(leftbiasf1);
        end
        
        function leftbiasf2 = get.LeftBiasF2(obj)
            %get.LeftBiasF2 Get the value for property LeftBiasF2
            leftbiasf2 = double(obj.JavaMessage.getLeftBiasF2);
        end
        
        function set.LeftBiasF2(obj, leftbiasf2)
            %set.LeftBiasF2 Set the value for property LeftBiasF2
            validateattributes(leftbiasf2, {'numeric'}, {'nonempty', 'scalar'}, 'yaml_valuesResponse', 'LeftBiasF2');
            
            obj.JavaMessage.setLeftBiasF2(leftbiasf2);
        end
        
        function leftbiasf3 = get.LeftBiasF3(obj)
            %get.LeftBiasF3 Get the value for property LeftBiasF3
            leftbiasf3 = double(obj.JavaMessage.getLeftBiasF3);
        end
        
        function set.LeftBiasF3(obj, leftbiasf3)
            %set.LeftBiasF3 Set the value for property LeftBiasF3
            validateattributes(leftbiasf3, {'numeric'}, {'nonempty', 'scalar'}, 'yaml_valuesResponse', 'LeftBiasF3');
            
            obj.JavaMessage.setLeftBiasF3(leftbiasf3);
        end
        
        function leftgainf1 = get.LeftGainF1(obj)
            %get.LeftGainF1 Get the value for property LeftGainF1
            leftgainf1 = double(obj.JavaMessage.getLeftGainF1);
        end
        
        function set.LeftGainF1(obj, leftgainf1)
            %set.LeftGainF1 Set the value for property LeftGainF1
            validateattributes(leftgainf1, {'numeric'}, {'nonempty', 'scalar'}, 'yaml_valuesResponse', 'LeftGainF1');
            
            obj.JavaMessage.setLeftGainF1(leftgainf1);
        end
        
        function leftgainf2 = get.LeftGainF2(obj)
            %get.LeftGainF2 Get the value for property LeftGainF2
            leftgainf2 = double(obj.JavaMessage.getLeftGainF2);
        end
        
        function set.LeftGainF2(obj, leftgainf2)
            %set.LeftGainF2 Set the value for property LeftGainF2
            validateattributes(leftgainf2, {'numeric'}, {'nonempty', 'scalar'}, 'yaml_valuesResponse', 'LeftGainF2');
            
            obj.JavaMessage.setLeftGainF2(leftgainf2);
        end
        
        function leftgainf3 = get.LeftGainF3(obj)
            %get.LeftGainF3 Get the value for property LeftGainF3
            leftgainf3 = double(obj.JavaMessage.getLeftGainF3);
        end
        
        function set.LeftGainF3(obj, leftgainf3)
            %set.LeftGainF3 Set the value for property LeftGainF3
            validateattributes(leftgainf3, {'numeric'}, {'nonempty', 'scalar'}, 'yaml_valuesResponse', 'LeftGainF3');
            
            obj.JavaMessage.setLeftGainF3(leftgainf3);
        end
        
        function rightbiasf1 = get.RightBiasF1(obj)
            %get.RightBiasF1 Get the value for property RightBiasF1
            rightbiasf1 = double(obj.JavaMessage.getRightBiasF1);
        end
        
        function set.RightBiasF1(obj, rightbiasf1)
            %set.RightBiasF1 Set the value for property RightBiasF1
            validateattributes(rightbiasf1, {'numeric'}, {'nonempty', 'scalar'}, 'yaml_valuesResponse', 'RightBiasF1');
            
            obj.JavaMessage.setRightBiasF1(rightbiasf1);
        end
        
        function rightbiasf2 = get.RightBiasF2(obj)
            %get.RightBiasF2 Get the value for property RightBiasF2
            rightbiasf2 = double(obj.JavaMessage.getRightBiasF2);
        end
        
        function set.RightBiasF2(obj, rightbiasf2)
            %set.RightBiasF2 Set the value for property RightBiasF2
            validateattributes(rightbiasf2, {'numeric'}, {'nonempty', 'scalar'}, 'yaml_valuesResponse', 'RightBiasF2');
            
            obj.JavaMessage.setRightBiasF2(rightbiasf2);
        end
        
        function rightbiasf3 = get.RightBiasF3(obj)
            %get.RightBiasF3 Get the value for property RightBiasF3
            rightbiasf3 = double(obj.JavaMessage.getRightBiasF3);
        end
        
        function set.RightBiasF3(obj, rightbiasf3)
            %set.RightBiasF3 Set the value for property RightBiasF3
            validateattributes(rightbiasf3, {'numeric'}, {'nonempty', 'scalar'}, 'yaml_valuesResponse', 'RightBiasF3');
            
            obj.JavaMessage.setRightBiasF3(rightbiasf3);
        end
        
        function rightgainf1 = get.RightGainF1(obj)
            %get.RightGainF1 Get the value for property RightGainF1
            rightgainf1 = double(obj.JavaMessage.getRightGainF1);
        end
        
        function set.RightGainF1(obj, rightgainf1)
            %set.RightGainF1 Set the value for property RightGainF1
            validateattributes(rightgainf1, {'numeric'}, {'nonempty', 'scalar'}, 'yaml_valuesResponse', 'RightGainF1');
            
            obj.JavaMessage.setRightGainF1(rightgainf1);
        end
        
        function rightgainf2 = get.RightGainF2(obj)
            %get.RightGainF2 Get the value for property RightGainF2
            rightgainf2 = double(obj.JavaMessage.getRightGainF2);
        end
        
        function set.RightGainF2(obj, rightgainf2)
            %set.RightGainF2 Set the value for property RightGainF2
            validateattributes(rightgainf2, {'numeric'}, {'nonempty', 'scalar'}, 'yaml_valuesResponse', 'RightGainF2');
            
            obj.JavaMessage.setRightGainF2(rightgainf2);
        end
        
        function rightgainf3 = get.RightGainF3(obj)
            %get.RightGainF3 Get the value for property RightGainF3
            rightgainf3 = double(obj.JavaMessage.getRightGainF3);
        end
        
        function set.RightGainF3(obj, rightgainf3)
            %set.RightGainF3 Set the value for property RightGainF3
            validateattributes(rightgainf3, {'numeric'}, {'nonempty', 'scalar'}, 'yaml_valuesResponse', 'RightGainF3');
            
            obj.JavaMessage.setRightGainF3(rightgainf3);
        end
    end
    
    methods (Access = protected)
        function cpObj = copyElement(obj)
            %copyElement Implements deep copy behavior for message
            
            % Call default copy method for shallow copy
            cpObj = copyElement@robotics.ros.Message(obj);
            
            % Create a new Java message object
            cpObj.JavaMessage = obj.createNewJavaMessage;
            
            % Iterate over all primitive properties
            cpObj.LeftBiasF1 = obj.LeftBiasF1;
            cpObj.LeftBiasF2 = obj.LeftBiasF2;
            cpObj.LeftBiasF3 = obj.LeftBiasF3;
            cpObj.LeftGainF1 = obj.LeftGainF1;
            cpObj.LeftGainF2 = obj.LeftGainF2;
            cpObj.LeftGainF3 = obj.LeftGainF3;
            cpObj.RightBiasF1 = obj.RightBiasF1;
            cpObj.RightBiasF2 = obj.RightBiasF2;
            cpObj.RightBiasF3 = obj.RightBiasF3;
            cpObj.RightGainF1 = obj.RightGainF1;
            cpObj.RightGainF2 = obj.RightGainF2;
            cpObj.RightGainF3 = obj.RightGainF3;
        end
        
        function reload(obj, strObj)
            %reload Called by loadobj to assign properties
            obj.LeftBiasF1 = strObj.LeftBiasF1;
            obj.LeftBiasF2 = strObj.LeftBiasF2;
            obj.LeftBiasF3 = strObj.LeftBiasF3;
            obj.LeftGainF1 = strObj.LeftGainF1;
            obj.LeftGainF2 = strObj.LeftGainF2;
            obj.LeftGainF3 = strObj.LeftGainF3;
            obj.RightBiasF1 = strObj.RightBiasF1;
            obj.RightBiasF2 = strObj.RightBiasF2;
            obj.RightBiasF3 = strObj.RightBiasF3;
            obj.RightGainF1 = strObj.RightGainF1;
            obj.RightGainF2 = strObj.RightGainF2;
            obj.RightGainF3 = strObj.RightGainF3;
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
            
            strObj.LeftBiasF1 = obj.LeftBiasF1;
            strObj.LeftBiasF2 = obj.LeftBiasF2;
            strObj.LeftBiasF3 = obj.LeftBiasF3;
            strObj.LeftGainF1 = obj.LeftGainF1;
            strObj.LeftGainF2 = obj.LeftGainF2;
            strObj.LeftGainF3 = obj.LeftGainF3;
            strObj.RightBiasF1 = obj.RightBiasF1;
            strObj.RightBiasF2 = obj.RightBiasF2;
            strObj.RightBiasF3 = obj.RightBiasF3;
            strObj.RightGainF1 = obj.RightGainF1;
            strObj.RightGainF2 = obj.RightGainF2;
            strObj.RightGainF3 = obj.RightGainF3;
        end
    end
    
    methods (Static, Access = {?matlab.unittest.TestCase, ?robotics.ros.Message})
        function obj = loadobj(strObj)
            %loadobj Implements loading of message from MAT file
            
            % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = robotics.ros.custom.msggen.morpheus_skates.yaml_valuesResponse.empty(0,1);
                return
            end
            
            % Create an empty message object
            obj = robotics.ros.custom.msggen.morpheus_skates.yaml_valuesResponse;
            obj.reload(strObj);
        end
    end
end