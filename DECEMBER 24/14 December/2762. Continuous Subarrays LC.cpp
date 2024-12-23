class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> minn, maxx; 
        int n = nums.size();
        int left = 0;
        long long ans = 0;
        for (int right = 0; right < n; right++)
        {
            while (!maxx.empty() && nums[maxx.back()] <= nums[right])  // Remove smaller elements from the maxx deque
                maxx.pop_back();
            maxx.push_back(right);  // Add the current index to the maxx deque

            while (!minn.empty() && nums[minn.back()] >= nums[right])  // Remove larger elements from the minn deque
                minn.pop_back();
            minn.push_back(right);  // Add the current index to the minn deque

            while (nums[maxx.front()] - nums[minn.front()] > 2){
                left++;
                if(minn.front() < left)
                    minn.pop_front();
                if(maxx.front() < left)
                    maxx.pop_front();
            }
            ans += (right - left + 1);  // Add the length to the answer
        }
        return ans;  // Return the final answer
    }
};
