class Solution {
public:
    void backtrack(int index, vector<vector<int>> &permutations, vector<int> &vec)
    {
        if(index==vec.size())
        {
            permutations.push_back(vec);
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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vec(nums.begin(), nums.end());
        vector<vector<int>> permutations;
        backtrack(0, permutations, vec);
        return permutations;
    }
};
