class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1;
        int lMax=0, rMax=0;
        long long trappedWater = 0;
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>lMax)
                    lMax = height[l];
                else
                    trappedWater += (lMax-height[l]);
                l++;
            }
            else
            {
                if(height[r]>rMax)
                    rMax = height[r];
                else
                    trappedWater += (rMax-height[r]);
                r--;
            }
        }
        return trappedWater;
    }
};
