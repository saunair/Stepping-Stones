directory = [{'rosbags\stance_tests_20th_march'}; {'rosbags\static_com_tests'}];
size(directory)
for i=1:size(directory,1)
    directory{i}
    file_names = dir((directory{i}));
    runsDir = {file_names.name};    
    
    for j=1:length(runsDir)
        runsDir{j}
    end
    
end