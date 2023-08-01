class Solution {
public:
    void backtrack(vector<vector<int>> &combinations, vector<int> &combination, int index, int n, int k)
    {
        if(k==0)
        {
            combinations.push_back(combination);
            return;
        }
        if(index>n)
            return;
        combination.push_back(index);
        backtrack(combinations, combination, index+1, n, k-1);
        combination.pop_back();
        backtrack(combinations, combination, index+1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> combination;
        backtrack(combinations, combination, 1, n, k);
        return combinations;
    }
};
