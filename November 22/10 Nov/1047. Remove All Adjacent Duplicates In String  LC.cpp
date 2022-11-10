class Solution {
public:
    string removeDuplicates(string str) {
        int n=str.length();
        string ans="";
        for(int i=0;i<n;i++){
            if(ans.size() && ans.back()==str[i])
                ans.pop_back();
            else
                ans.push_back(str[i]);
        }
        return ans;
    }
};
