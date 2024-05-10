class Solution{
public:
    set<vector<int>> combinations;
    void backtrack(vector<int> &arr, vector<int> &combination, int sum, int k, int index)
    {
        int len = arr.size();
        
        if(sum==k)
        {
            combinations.insert(combination);
            return;
        }
        if(index>=len || sum>k)
            return;
        combination.push_back(arr[index]);
        backtrack(arr, combination, sum+arr[index], k, index+1);
        combination.pop_back();
        backtrack(arr, combination, sum, k, index+1);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        vector<int> combination;
        sort(arr.begin(), arr.end());
        backtrack(arr, combination, 0, k, 0);
        vector<vector<int>> ans(combinations.begin(), combinations.end());
        return ans;
    }
    
};
