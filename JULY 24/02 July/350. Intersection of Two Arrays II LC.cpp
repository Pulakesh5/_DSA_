class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ind1=0, ind2=0;
        int size1 = nums1.size(), size2 = nums2.size();
        vector<int> intersection;
        while(ind1<size1 && ind2<size2)
        {
            if(nums1[ind1]==nums2[ind2])
            {
                intersection.push_back(nums1[ind1]);
                ind1++;
                ind2++;
            }
            else if(nums1[ind1] < nums2[ind2])
                ind1++;
            else
                ind2++;
        }
        return intersection;
    }
};
