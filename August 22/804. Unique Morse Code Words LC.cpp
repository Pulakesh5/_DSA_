class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<char,string> mp={{'a',".-"},{'b',"-..."},{'c',"-.-."},{'d',"-.."},{'e',"."},{'f',"..-."},{'g',"--."},{'h',"...."},{'i',".."},{'j',".---"},{'k',"-.-"},{'l',".-.."},{'m',"--"},{'n',"-."},{'o',"---"},{'p',".--."},{'q',"--.-"},{'r',".-."},{'s',"..."},{'t',"-"}, {'u',"..-"},{'v',"...-"},{'w',".--"},{'x',"-..-"},{'y',"-.--"},{'z',"--.."}};
        
        set<string> st;
        string transform;
        for(string &word:words){
            transform="";
            for(auto ch:word){
                transform+=mp[ch];
            }
            st.insert(transform);
        }
        return st.size();
    }
};
