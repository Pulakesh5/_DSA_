class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> mp;
        
        for(auto i:nums1)
            for(auto j:nums2)
                mp[i+j]++;
      
        int count=0;
      
      for(auto k:nums3)
            for(auto l:nums4)
                count+=mp[-(k+l)];
        return count;
    }
};
