class Solution {
public:
    void backtrack(int index, set<vector<int>> &permutations, vector<int> &vec)
    {
        if(index==vec.size())
        {
            permutations.insert(vec);
            return;
        }
        backtrack(index+1, permutations, vec);
        for(int j=index+1; j<vec.size(); j++)
        {
            swap(vec[index], vec[j]);
            backtrack(index+1, permutations, vec);
            swap(vec[index], vec[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> vec(nums.begin(), nums.end());
        set<vector<int>> permutations;
        backtrack(0, permutations, vec);
        vector<vector<int>> ans(permutations.begin(), permutations.end());
        return ans;
    }
};
