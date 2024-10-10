class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> monotonicStack;

        int N = nums.size(), maxWidthRamp = 0;
        for (int j=0; j<N; j++) {
            if(monotonicStack.empty() || nums[monotonicStack.top()] > nums[j])
                monotonicStack.push(j);
        }

        for(int i=N-1; i>=0; i--) {
            while(!monotonicStack.empty() && nums[monotonicStack.top()]<=nums[i]) {
                maxWidthRamp = max(maxWidthRamp, i-monotonicStack.top());
                monotonicStack.pop();
            }
        }

        return maxWidthRamp;
    }
};
