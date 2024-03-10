class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len1 = nums1.size(), len2 = nums2.size();
        int p1=0, p2=0;
        vector<int> intersection;
        while(p1<len1 && p2<len2)
        {
            if(nums1[p1]==nums2[p2])
            {
                if(intersection.size()==0 || intersection.back()<nums1[p1])
                    intersection.push_back(nums1[p1]);
                p1++;
                p2++;
            }
            else if(nums1[p1]<nums2[p2])
                p1++;
            else 
                p2++;
        }
        return intersection;
    }
};
