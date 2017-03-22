function combineStanceForceData(experimentFolder)
    matFileList = dir(strcat('../Mat Files/',experimentFolder));
    expNormForceTable = table();
    for fileIdx = 3:size(matFileList,1)
        matFileName = matFileList(fileIdx).name;
        load(strcat('../Mat Files/',experimentFolder,'/',matFileName),'normalized_force_per_sensor'); 
       
        %Check for double stance
        if(isempty(findstr('Double',matFileName)) == 0)
            Label = 1.*ones(size(normalized_force_per_sensor,1),1);
        else
        
            %Check for left single stance
            if(isempty(findstr('Left',matFileName)) == 0)
                Label = 2.*ones(size(normalized_force_per_sensor,1),1);    
            else
        
                %Check for right single stance
                if(isempty(findstr('Right',matFileName)) == 0)
                    Label = 3.*ones(size(normalized_force_per_sensor,1),1);
                else
                    error('Cannot determine proper label');
                end
            end
        end
        
        labelTable = table(Label);
        normalized_force_per_sensor = [normalized_force_per_sensor labelTable];
        expNormForceTable = [expNormForceTable; normalized_force_per_sensor];
        save(strcat('../Mat Files/',experimentFolder,'/',experimentFolder,'.mat'),'expNormForceTable');
        writetable(expNormForceTable,strcat('../Mat Files/',experimentFolder,'/',experimentFolder,'.csv'));
    end
end