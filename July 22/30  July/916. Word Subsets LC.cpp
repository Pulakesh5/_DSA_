class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<vector<int>> _words1(words1.size(),vector<int>(26,-1));
        vector<vector<int>> _words2(words2.size(),vector<int>(26,-1));
        
        int n1=words1.size(),n2=words2.size();
        for(int i=0;i<n1;i++){
            for(int j=0;j<words1[i].size();j++)
                _words1[i][words1[i][j]-'a']++;
        }
        
        for(int i=0;i<n2;i++){
            for(int j=0;j<words2[i].size();j++)
                _words2[i][words2[i][j]-'a']++;
        }
      
        vector<int> universal(26,-1);
        for(int i=0;i<26;i++){
            for(int j=0;j<n2;j++)
                universal[i]=max(universal[i],_words2[j][i]);
        }
      
        bool flag=true;
        vector<string> ans;
        for(int i=0;i<n1;i++){
            flag=true;
            for(int j=0;j<26 && flag;j++){
                if(universal[j]>_words1[i][j])
                    flag=false;
            }
            if(flag) ans.push_back(words1[i]);
        }
        
        return ans;
    }
};
