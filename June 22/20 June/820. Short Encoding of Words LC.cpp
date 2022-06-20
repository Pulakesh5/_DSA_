class Solution {
public:
    static bool comp(string str1, string str2){
        return str1.length()>str2.length();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string, int> mp;
        string str;
        sort(words.begin(), words.end(), comp);
        
        int indice=0,count=0;
        for(auto &word:words){
            int len=word.size();
            str="";
            if(mp.find(word)==mp.end()){
                for(int i=0;i<len;i++){
                    str = word[len-1-i]+str;
                    mp[str]=indice;
                }
                count+=(len+1);
            }
            indice++;
        }
        return count;
    }
};
