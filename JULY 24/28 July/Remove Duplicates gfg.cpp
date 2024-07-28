class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        vector<int> visited(26,0);
        string unique = "";
        for(char ch:str)
        {
            if(visited[ch-'a']==0)
            {
                visited[ch-'a'] = 1;
                unique.push_back(ch);
            }
        }
        return unique;
    }
};
