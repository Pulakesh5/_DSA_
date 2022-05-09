class Solution {
public:
    map<char,vector<char>> mp;
    
    vector<string> letterCombinations(string dig) {
        mp['2']={'a','b','c'};
        mp['3']={'d', 'e', 'f'};
        mp['4']={'g', 'h', 'i'};
        mp['5']={'j', 'k', 'l'};
        mp['6']={'m', 'n', 'o'};
        mp['7']={'p', 'q', 'r', 's'};
        mp['8']={'t', 'u', 'v'};
        mp['9']={'w', 'x', 'y', 'z'};
        int n=dig.length();
        vector<string> ans;
        if(n==0) return ans;
        string s;
        rec(ans,s,dig,0,n);
        return ans;
    }
    
    void rec(vector<string> &ans, string &s,string &dig,int i,int n){
        if(i==n){
            ans.push_back(s);
        }
        for(int j=0;j<mp[dig[i]].size();j++){
            s+=mp[dig[i]][j];
            rec(ans,s,dig,i+1,n);
            s.pop_back();
        }
        //rec(ans,)
        
    }
    
    
};
