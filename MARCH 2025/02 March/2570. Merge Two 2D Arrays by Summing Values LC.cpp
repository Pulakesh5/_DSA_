class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int index1 = 0, index2 = 0;
        int N1 = nums1.size(), N2 = nums2.size();
        int id1, id2, num1, num2;
        vector<vector<int>> mergedArray;

        while(index1<N1 && index2<N2)
        {
            id1 = nums1[index1][0];
            id2 = nums2[index2][0];
            num1 = nums1[index1][1];
            num2 = nums2[index2][1];
            if(id1 == id2)
            {
                mergedArray.push_back({id1, num1+num2});
                index1++;
                index2++;
            }
            else if(id1<id2)
            {
                mergedArray.push_back({id1, num1});
                index1++;
            }
            else
            {
                mergedArray.push_back({id2, num2});
                index2++;
            }
        }

        while(index1<N1)
        {
            id1 = nums1[index1][0];
            num1 = nums1[index1][1];
            mergedArray.push_back({id1, num1});
                index1++;
        }

        while(index2<N2)
        {
            id2 = nums2[index2][0];
            num2 = nums2[index2][1];
            mergedArray.push_back({id2, num2});
                index2++;
        }

        return mergedArray;
    }
};
