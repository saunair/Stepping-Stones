classdef CustomMsgConsts
    %CustomMsgConsts This class stores all message types
    %   The message types are constant properties, which in turn resolve
    %   to the strings of the actual types.
    
    %   Copyright 2017 The MathWorks, Inc.
    
    properties (Constant)
        morpheus_skates_integrated_message = 'morpheus_skates/integrated_message'
        morpheus_skates_pounds_display = 'morpheus_skates/pounds_display'
        morpheus_skates_sensors_normalized = 'morpheus_skates/sensors_normalized'
        morpheus_skates_sensors_normalizedRequest = 'morpheus_skates/sensors_normalizedRequest'
        morpheus_skates_sensors_normalizedResponse = 'morpheus_skates/sensors_normalizedResponse'
        morpheus_skates_skate_command = 'morpheus_skates/skate_command'
        morpheus_skates_skate_feedback = 'morpheus_skates/skate_feedback'
        morpheus_skates_user_force_normalized = 'morpheus_skates/user_force_normalized'
        morpheus_skates_user_shoe_size = 'morpheus_skates/user_shoe_size'
        morpheus_skates_user_shoe_sizeRequest = 'morpheus_skates/user_shoe_sizeRequest'
        morpheus_skates_user_shoe_sizeResponse = 'morpheus_skates/user_shoe_sizeResponse'
        morpheus_skates_yaml_values = 'morpheus_skates/yaml_values'
        morpheus_skates_yaml_valuesRequest = 'morpheus_skates/yaml_valuesRequest'
        morpheus_skates_yaml_valuesResponse = 'morpheus_skates/yaml_valuesResponse'
        morpheus_skates_zero_point = 'morpheus_skates/zero_point'
        morpheus_skates_zero_pointRequest = 'morpheus_skates/zero_pointRequest'
        morpheus_skates_zero_pointResponse = 'morpheus_skates/zero_pointResponse'
    end
    
    methods (Static, Hidden)
        function messageList = getMessageList
            %getMessageList Generate a cell array with all message types.
            %   The list will be sorted alphabetically.
            
            persistent msgList
            if isempty(msgList)
                msgList = cell(17, 1);
                msgList{1} = 'morpheus_skates/integrated_message';
                msgList{2} = 'morpheus_skates/pounds_display';
                msgList{3} = 'morpheus_skates/sensors_normalized';
                msgList{4} = 'morpheus_skates/sensors_normalizedRequest';
                msgList{5} = 'morpheus_skates/sensors_normalizedResponse';
                msgList{6} = 'morpheus_skates/skate_command';
                msgList{7} = 'morpheus_skates/skate_feedback';
                msgList{8} = 'morpheus_skates/user_force_normalized';
                msgList{9} = 'morpheus_skates/user_shoe_size';
                msgList{10} = 'morpheus_skates/user_shoe_sizeRequest';
                msgList{11} = 'morpheus_skates/user_shoe_sizeResponse';
                msgList{12} = 'morpheus_skates/yaml_values';
                msgList{13} = 'morpheus_skates/yaml_valuesRequest';
                msgList{14} = 'morpheus_skates/yaml_valuesResponse';
                msgList{15} = 'morpheus_skates/zero_point';
                msgList{16} = 'morpheus_skates/zero_pointRequest';
                msgList{17} = 'morpheus_skates/zero_pointResponse';
            end
            
            messageList = msgList;
        end
        
        function serviceList = getServiceList
            %getServiceList Generate a cell array with all service types.
            %   The list will be sorted alphabetically.
            
            persistent svcList
            if isempty(svcList)
                svcList = cell(4, 1);
                svcList{1} = 'morpheus_skates/sensors_normalized';
                svcList{2} = 'morpheus_skates/user_shoe_size';
                svcList{3} = 'morpheus_skates/yaml_values';
                svcList{4} = 'morpheus_skates/zero_point';
            end
            
            % The message list was already sorted, so don't need to sort
            % again.
            serviceList = svcList;
        end
    end
end
