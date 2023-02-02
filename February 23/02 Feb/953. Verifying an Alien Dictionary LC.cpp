map<char,int> mp;
bool cmp(string a, string b){
    int n = min(a.length(), b.length());
    for(int i = 0; i < n; i++){
        if(mp[a[i]] < mp[b[i]]){
            return true;
        }
        else if(mp[a[i]] > mp[b[i]]){
            return false;
        }
    }
    if(a.length() <= b.length()){
        return true;
    }
    return false;
}
class Solution {
public:
        
    bool isAlienSorted(vector<string>& words, string order) {

        for(int i=0;i<26;i++)
            mp[order[i]]=i;
        
        vector<string> t=words;
        sort(t.begin(), t.end(), cmp);
        return words==t;
    }
};
