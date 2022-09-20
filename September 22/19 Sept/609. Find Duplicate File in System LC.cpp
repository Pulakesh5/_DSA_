class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string,vector<string>> files;
        vector<vector<string>> duplicates;
        
        for(string &path:paths)
        {
            stringstream ss(path);
            string root;
            string sub;
            string fileName,fileContent;
            int start,end;
            getline(ss,root,' ');
            
            while(getline(ss,sub,' '))
            {
                fileName = root+'/'+sub.substr(0,sub.find('('));
                start=sub.find('(');
                end=sub.find(')');
                fileContent=sub.substr(start+1,start-end-1);
                files[fileContent].push_back(fileName);
            }
            
        }
        
        for(auto vec:files)
        {
            if(vec.second.size()>1)
                duplicates.push_back(vec.second);
        }
        
        return duplicates;
        
    }
};
