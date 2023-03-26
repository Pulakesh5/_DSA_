class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int ans = -1;
        vector<bool> vis(n, false);
    
        for(int i = 0; i < n; i++)
        {
            int j = i;
            int t = 0;
            unordered_map<int,int> s;
            while(j != -1 && !vis[j] && s.find(j) == s.end())
            {
                s[j] = t;
                t++;
                vis[j] = true;
                j = edges[j];
                if(j != -1 && s.find(j) != s.end())
                {
                    ans = max(ans, t-s[j]);
                    break;
                }
            }
        }
        return ans;
    }
};
