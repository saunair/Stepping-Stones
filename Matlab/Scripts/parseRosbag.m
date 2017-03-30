function parseRosbag(filename)
    % Get rosbag
    bag = rosbag(strcat('..\rosbags\',filename,'.bag'));
          
    % Parse available topics  
    if(isempty(strmatch('/left_command',bag.AvailableTopics.Properties.RowNames)) == 0)
        left_cmd = parseTopic(bag,'/left_command','morpheus_skates/skate_command');        
    end

    if(isempty(strmatch('/right_command',bag.AvailableTopics.Properties.RowNames)) == 0)
        right_cmd = parseTopic(bag,'/right_command','morpheus_skates/skate_command');        
    end
 
    if(isempty(strmatch('/left_feedback',bag.AvailableTopics.Properties.RowNames)) == 0)
        left_fbk = parseTopic(bag,'/left_feedback','morpheus_skates/skate_feedback');        
    end

    if(isempty(strmatch('/right_feedback',bag.AvailableTopics.Properties.RowNames)) == 0)
        right_fbk = parseTopic(bag,'/right_feedback','morpheus_skates/skate_feedback');        
    end
    
    if(isempty(strmatch('/pounds_per_sensor',bag.AvailableTopics.Properties.RowNames)) == 0)
        pounds_per_sensor = parseTopic(bag,'/pounds_per_sensor','morpheus_skates/pounds_display');
    end
    
    if(isempty(strmatch('/normalized_force_per_sensor',bag.AvailableTopics.Properties.RowNames)) == 0)
        normalized_force_per_sensor = parseTopic(bag,'/normalized_force_per_sensor','morpheus_skates/user_force_normalized');
    end

%     if(isempty(strmatch('/total_message',bag.AvailableTopics.Properties.RowNames)) == 0)
%         total_message = parseTopic(bag,'/total_message','morpheus_skates/integrated_message');
%     end
    %if(isempty(strmatch('/user_position_offset',bag.AvailableTopics.Properties.RowNames)) == 0)
    %    user_position_offset = parseTopic(bag,'/user_position_offset','std_msgs/Float64');
    %end
    
    
    %if(isempty(strmatch('/tf',bag.AvailableTopics.Properties.RowNames)) == 0)
    %     = parseTopic(bag,'/normalized_force_per_sensor','morpheus_skates/user_force_normalized');
    %end
    
    save(strcat('..\Mat Files\',filename,'.mat'));    
end

function topicTable = parseTopic(bag,topicName,messageType)
    bagSelect = select(bag,'Topic',topicName);
    bagMsgs = readMessages(bagSelect);
    
    msgInfo = rosmsg('show',messageType);
    msgInfoCellArray = strread(msgInfo, '%s', 'delimiter', sprintf('\n'));
    
    for msgNum = 1:size(bagMsgs,1)
        msg = bagMsgs{msgNum};
        vars = {'Time'};
        topic(msgNum,1) = double(msg.Header.Stamp.Nsec)*1e-9 + ...
            double(msg.Header.Stamp.Sec) - bag.StartTime;
        for fieldNum = 2:size(msgInfoCellArray,1)
            fieldString = strsplit(msgInfoCellArray{fieldNum});
            if(isempty(fieldString{1}))
                continue
            end
            fieldName = fieldString{2};
            vars{fieldNum} = fieldName;
            topic(msgNum,fieldNum) = eval(strcat('msg.',fieldName));
        end
    end
    topicTable = array2table(topic,'VariableNames',vars);
end
