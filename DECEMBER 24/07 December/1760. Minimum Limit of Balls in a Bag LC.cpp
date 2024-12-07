class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1, high = *max_element(nums.begin(), nums.end());
        int mid, count, ans = high;
        while(low<=high)
        {
            mid = (low+high)/2;
            count = 0;
            // cout<<low<<" "<<high<<", "<<mid;
            for(int num:nums)
            {
                count += ((num+mid-1)/mid-1);
            }
            // cout<<" : "<<count<<endl; 
            if(count<=maxOperations)
            {
                ans = min(ans, mid);
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};
