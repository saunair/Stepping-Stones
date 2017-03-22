function combineComForceData(experimentFolder)
    matFileList = dir(strcat('../Mat Files/',experimentFolder));
    expNormForceTable = table();
    for fileIdx = 3:size(matFileList,1)
        matFileName = matFileList(fileIdx).name;
        load(strcat('../Mat Files/',experimentFolder,'/',matFileName),'normalized_force_per_sensor'); 
        nfps = normalized_force_per_sensor;  
        nfps.com_x = ((nfps.LeftNormalFrontInner + ...
            nfps.LeftNormalFrontOuter + nfps.RightNormalFrontInner +...
            nfps.RightNormalFrontOuter).*7.5 + (nfps.LeftNormalRear +...
            nfps.RightNormalRear).*(-3.5))./nfps.NormalTotal;
        expNormForceTable = [expNormForceTable; nfps];
        save(strcat('../Mat Files/',experimentFolder,'/',experimentFolder,'.mat'),'expNormForceTable');
%         writetable(expNormForceTable,strcat('../Mat Files/',experimentFolder,'/',experimentFolder,'.csv'));
    end
end