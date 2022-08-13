class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int wordLength=words[0].size(), countWord=words.size();
        vector<int> indices;
        
        unordered_map<string,int> count;
        for(string word:words)
            count[word]++;
        
        int slen=s.length(),j;
        
        for(int i=0;i<(slen-countWord*wordLength+1);i++){
            unordered_map<string,int> seen;
            for(j=0;j<countWord;j++)
            {
                string seenWord=s.substr(i+j*wordLength,wordLength);
                if(count.find(seenWord)!=count.end()){
                    seen[seenWord]++;
                    if(seen[seenWord]>count[seenWord])
                        break;
                }
                else
                    break;
            }
            if(j==countWord) indices.push_back(i);   
        }
        return indices;
    }
};
