directory = [{'stance_tests_20th_march\'}; {'static_com_tests\'}];
directory1 = [{'..\rosbags\stance_tests_20th_march'}; {'..\rosbags\static_com_tests'}];
size(directory1);
for i=1:size(directory1,1)
    directory1{i};
    file_names = dir((directory1{i}));
    runsDir = {file_names.name};
    files=[];
    for j=3:length(runsDir)
        fileparse = runsDir{j};
        pattern = '.bag';
        replace = '';
        fileparse = regexprep(fileparse,pattern,replace);
        filename = strcat(directory(i),fileparse)     
        parseRosbag(filename{1});
%       files = [files, filename]
    end
%disp(filename)    
end
