class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i=0; i<(n-1); i++)
        {
            if(binary_search(arr.begin()+i+1, arr.end(), target-arr[i]))
                return true;
        }
        return false;
    }
};
