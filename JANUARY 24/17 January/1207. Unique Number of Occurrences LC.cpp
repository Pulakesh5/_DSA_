class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n=arr.size(), j;
        map<int,int> freqCount;
        for(int i=0; i<n; )
        {
            j=i+1;
            while(j<n && arr[j]==arr[i])
                j++;
            freqCount[j-i]++;
            i=j;
        }
        for(auto it:freqCount)
        {
            if(it.second>1)
                return false;
        }
        return true;
    }
};
