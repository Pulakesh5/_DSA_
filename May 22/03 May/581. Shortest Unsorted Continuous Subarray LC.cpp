class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        int n=nums.size();
        int l=0,r=n-1;
        for(;l<n;l++)
            if(sorted[l]!=nums[l]) break;
        if(l==n) return 0;
        for(; r>=0;r--)
            if(sorted[r]!=nums[r]) break;
        //if(r==n-1) return n;
        return n-(l+n-1-r);
        // 15 6 4 8 10 9 2
        // 2 4 6 8 9 10 15
    }
};
