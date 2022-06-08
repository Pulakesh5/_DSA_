
// learnt how to use istringstream to  tokenize a long stream made up of words
class Solution {
public:
    string reverseWords(string s) {
        string token;
        istringstream ss(s);
        vector<string> vec;
        while(ss>>token){
            vec.push_back(token);
            
        }
        reverse(vec.begin(), vec.end());
        string ans="";
        for(auto str:vec){
            ans+=str;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};
