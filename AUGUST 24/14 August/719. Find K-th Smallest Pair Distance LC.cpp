class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums[n-1] - nums[0];

        for(int count=0; l<r; count = 0)
        {
            int mid = l+(r-l)/2;
            for(int i=0, j=0; i<n; i++)
            {
                while(j<n && nums[j]<=nums[i]+mid)
                    j++;
                count+=(j-i-1);
            }
            if(count<k)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};
