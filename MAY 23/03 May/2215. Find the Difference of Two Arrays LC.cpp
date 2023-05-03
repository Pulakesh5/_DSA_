class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> exists1(2005,0), exists2(2005,0), common(2005,0);
        for(int num:nums1)
            exists1[num+1000]++;
        for(int num:nums2)
            exists2[num+1000]++;

        for(int i=0;i<=2000;i++)
        {
            if(exists1[i]>0 && exists2[i]>0)
            {
                exists1[i]=-1;
                exists2[i]=-1;
            }
        }
        vector<vector<int>> ans(2);
        for(int i=0;i<=2000;i++)
        {
            if(exists1[i]>0)
                ans[0].push_back(i-1000);
            if(exists2[i]>0)
                ans[1].push_back(i-1000);
        }

        return ans;
    }
};ˇ
