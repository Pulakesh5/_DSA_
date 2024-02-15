class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long perimeter=0;
        int n=nums.size();
        for(int i=0; i<n; i++)
            perimeter+=nums[i];
        sort(nums.begin(), nums.end());
        for(int i=n-1; i>-1; i--)
        {
            if(perimeter>2*nums[i])
                return perimeter;
            perimeter-=nums[i];
        }
        return -1;
    }
};
