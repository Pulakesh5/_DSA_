class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        unordered_map<int,int> remainder_count;
        vector<int> list;
        for(auto &row:grid) {
            for(int num:row)
            {
                remainder_count[num%x]++;
                list.push_back(num);
            }
        }
        
        if(remainder_count.size()>1)
            return -1;
        
        sort(list.begin(), list.end());
        
        int m = grid.size(), n = grid[0].size();
        int target = list[m*n/2], ans = 0;

        for(int i=0; i<(m*n); i++) {
            ans += abs(list[i]-target)/x;
        }
        return ans;
    }
};
