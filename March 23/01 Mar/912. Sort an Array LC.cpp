class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> arr(nums.begin(), nums.end());
        sort(arr.begin(), arr.end());

        return arr;
    }
};
