// UnOptimized code : O((m+n)log(m+n))
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m,p2=0;
        while(p2<n){
            swap(nums1[p1],nums2[p2]);
            p1++;p2++;
        }
        sort(nums1.begin(), nums1.end());
    }
};
// Optimal Solution: O(m+n)
//   this solution starts from end so when all the elements of second array has been copied to first one
//   the remaining elements of first array is already in sorted  order
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1,p2=n-1,pfinal=m+n-1;
        while(p2>=0){
            if(p1>=0 && nums1[p1]>nums2[p2])
                nums1[pfinal--]=nums1[p1--];
            else
                nums1[pfinal--]=nums2[p2--];
        }
    }
};
