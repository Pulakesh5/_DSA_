class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        set<string> uniqueFolders;
        for(string f:folder)
        {
            string file_path = "";
            bool unique = true;
            int len = f.size();
            for(int i=0; i<len; i++)
            {
                file_path.push_back(f[i]);
                if((i+1)<len && f[i+1] =='/' && uniqueFolders.find(file_path)!=uniqueFolders.end())
                {
                    unique = false;
                    break;
                }
            }
            if(unique)
                uniqueFolders.insert(file_path);
        }
        vector<string> removedSubFolders(uniqueFolders.begin(), uniqueFolders.end());
        return removedSubFolders;
    }
};
