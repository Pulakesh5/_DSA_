class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        int len = arr.size();
        vector<int> visited(len,0);
        map<int,vector<int>> char_freq;
        for(int i=0; i<len; i++)
        {
            vector<int> freq(26);
            for(char ch:arr[i])
                freq[ch-'a']++;
            char_freq[i] = freq;
        }
        
        vector<vector<string>> anagram_groups;
        
        for(int i=0; i<len; i++)
        {
            if(visited[i])
                continue;
            visited[i] = 1;
            vector<string> group;
            group.push_back(arr[i]);
            
            for(int j=i+1; j<len; j++)
            {
                if(char_freq[i]==char_freq[j])
                {
                    group.push_back(arr[j]);
                    visited[j] = 1;
                }
            }
            anagram_groups.push_back(group);
        }
        
        // sort(anagram_groups[group].begin(), anagram_groups[group].end());
        
        return anagram_groups;
    }
};
