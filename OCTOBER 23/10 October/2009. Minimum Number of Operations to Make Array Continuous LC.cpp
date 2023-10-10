class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size(), ans = N, j = 0;
        sort(begin(nums), end(nums));
        nums.erase(unique(begin(nums), end(nums)), end(nums)); // only keep unique elements
        int M = nums.size();
        for (int i = 0; i < M; ++i) {
            while (j < M && nums[j] < nums[i] + N) ++j; 
            ans = min(ans, N - j + i); 
        }
        return ans;
    }
};
