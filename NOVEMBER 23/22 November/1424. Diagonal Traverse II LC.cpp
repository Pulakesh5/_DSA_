class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int row=nums.size(), maxKey=0, sz;

        vector<int> order;
        unordered_map<int,vector<int>> diagonals;
        for(int i=0; i<row; i++)
        {
            sz = nums[i].size();
            maxKey = max(maxKey,i+sz-1);
            for(int j=0; j<sz; j++)
                diagonals[i+j].push_back(nums[i][j]);
        }
        for(int key=0; key<=maxKey; key++)
        {
            for(auto it=diagonals[key].rbegin(); it!=diagonals[key].rend(); it++)
                order.push_back(*it);
        }
        return order;
    }
};      
