class Solution {
public:
    int maxLength(vector<string>& arr) {
        int maxLength=0;
        int n = arr.size();
        for(int bitset=0; bitset<(1<<n); bitset++)
        {
            vector<int> count(26);
            bool safeToMerge=true;
            int mergedStringLen = 0;
            for(int i=0; i<min(n,16); i++)
            {
                if(bitset&(1<<i))
                {
                    for(char ch:arr[i])
                        count[ch-'a']++;
                }
            }
            for(int i=0; i<26; i++)
            {
                if(count[i]>1)
                    safeToMerge = false;
            }
            if(safeToMerge)
            {
                for(int i=0; i<min(n,16); i++)
                {
                    if(bitset&(1<<i))
                        mergedStringLen+=arr[i].size();
                }
            }
            maxLength = max(maxLength, mergedStringLen);
        }
        return maxLength;
    }
};
