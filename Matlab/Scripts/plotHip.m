function ts = plotHip(msg_tf)
    time = [];
    data = [];
    dataIdx = 1;
    for msgNum = 1:size(msg_tf,1)
       msg = msg_tf{msgNum};
       childFrameId = msg.Transforms.ChildFrameId;
       if strcmp(childFrameId,'left_hip_1')
           time(dataIdx) = double(msg.Transforms.Header.Stamp.Sec) + ...
               double(msg.Transforms.Header.Stamp.Nsec)*1e-9;
%            right_hip_posn = msg.Transforms.Transform.Translation.X;
%            data(dataIdx) = 0.5*(left_hip_posn+right_hip_posn);
           data(dataIdx) = msg.Transforms.Transform.Translation.X;
           dataIdx = dataIdx + 1;
%            left_hip_posn = msg.Transforms.Transform.Translation.X;
       end
       
%        if strcmp(childFrameId,'right_hip_1')
%            time(dataIdx) = msg.Transforms.Header.Stamp.Sec + ...
%                msg.Transforms.Header.Stamp.Nsec*1e-9;
%            right_hip_posn = msg.Transforms.Transform.Translation.X;
%            data(dataIdx) = 0.5*(left_hip_posn+right_hip_posn);
%            dataIdx = dataIdx + 1;
%        end
    end
    ts = timeseries(data,time,'Name','hip.Translation.X');
end