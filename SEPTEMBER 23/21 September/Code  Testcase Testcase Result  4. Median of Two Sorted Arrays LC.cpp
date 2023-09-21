class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int mid=(n1 + n2 + 1)/2;
        
        int p1=0,p2=0;
        pair<int,int> median={-1,-1};//{array,position}
        int i=0;
        while(i<mid && p1<n1 && p2<n2){
            if(nums1[p1]<=nums2[p2]){
                median={0,p1};
                p1++;
            }
            else{
                median={1,p2};
                p2++;
            }
            i++;
        }
        if(i<mid){
            while(i<mid && p1<n1)
            {
                median={0,p1++};
                i++;
            }
            
            while(i<mid && p2<n2){
                median={1,p2++};
                i++;
            }
        }
        if((n1+n2)&1){
            if(median.first==0) return nums1[median.second];
            return nums2[median.second];
        }
        else{
            double med=(median.first==0? nums1:nums2)[median.second];
            if(p1<n1 && p2<n2){
                med+=min(nums1[p1],nums2[p2]);
            }
            else if(p1<n1)
                med+=nums1[p1];
            else
                med+=nums2[p2];
            return med/2.0;
        }
        
    }
};
