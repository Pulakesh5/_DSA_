class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> prefix1;
        for(int num:arr1)
        {
            int exp = 10;
            prefix1.insert(num);
            // cout<<num<<" ";
            while(num>=exp)
            {
                prefix1.insert(num/exp);
                // cout<<num/exp<<" ";
                exp *= 10;
            }
            // cout<<endl;
        }
        int longestPrefix = 0, len, prefix2;
        for(int num:arr2)
        {
            int exp = 10;
            if(prefix1.find(num)!=prefix1.end())
            {
                len = log10(num)+1;
                longestPrefix = max(longestPrefix, len);
            }
            while(num>=exp)
            {
                prefix2 = (num/exp);
                if(prefix1.find(prefix2)!=prefix1.end())
                {
                    len = log10(prefix2)+1;
                    longestPrefix = max(longestPrefix, len);
                }
                exp *= 10;
            }
        }
        return longestPrefix;
    }
};
