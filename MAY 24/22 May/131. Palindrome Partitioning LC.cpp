class Solution {
private:
    vector<vector<string>> partitions;
    bool isPalindrome(string s, int l, int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void palindromePartition(string s, int pos, vector<string> &partition)
    {
        int n = s.size();
        if(pos==n)
        {
            partitions.push_back(partition);
        }
        for(int i=pos; i<n; i++)
        {
            if(isPalindrome(s,pos,i))
            {
                partition.push_back(s.substr(pos,i-pos+1));
                palindromePartition(s, i+1, partition);
                partition.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        palindromePartition(s, 0, partition);
        return partitions;
    }
};
