class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int i=0, j, n=arr.size();
        while(i<n)
        {
            j = i;
            while(j<n && arr[i]==arr[j])
                j++;
            if((j-i)>(n/4))
                return arr[i];
            i = j;
        }
        return -1;
    }
};
