class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len=s.length();
        vector<vector<string>> ans;
        vector<string> arr;
        part(s, 0, arr, ans);
        return ans;
    }
    void part(string s, int start, vector<string> &arr, vector<vector<string>> &ans)
    {
        int n=s.length();
        if(start==n)
            ans.push_back(arr);
        else{
            for(int i=start; i<n;i++)
            {
                if(ispal(s, start, i))
                {
                    arr.push_back(s.substr(start, i-start+1));
                    part(s, i+1, arr, ans);
                    arr.pop_back();
                }
            }
        }
    }
    bool ispal(string s, int strt, int end){
        while(strt<end){
            if(s[strt++]!=s[end--])
                return  false;
        }
        return true;
    }
};
