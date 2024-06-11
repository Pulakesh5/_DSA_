class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int len1 = arr1.size(), len2 = arr2.size();
        int p1=0;
        for(int i=0; i<len2; i++)
        {
            for(int j=p1; j<len1; )
            {
                if(arr1[j]!=arr2[i])
                {
                    j++;
                    continue;
                }
                swap(arr1[j],arr1[p1]);
                p1++;
                j++;
            }
        }
        if(p1==len1)
            return arr1;
        sort(arr1.begin()+p1,arr1.end());
        return arr1;
    }
};
