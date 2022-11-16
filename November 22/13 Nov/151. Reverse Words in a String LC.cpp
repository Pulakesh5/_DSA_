class Solution {
public:
    string reverseWords(string s) {
        string v;
        
        stringstream ss(s);
        string word;

        while(ss>>word)
        {
            reverse(word.begin(), word.end());
            v = v + word;
            v.push_back(' ');
        }
        v.pop_back();
        reverse(v.begin(),v.end());
        return v;
    }
};
