class Solution {
  public:
    int distinctSubsequence(string str)
    {
        unordered_map<char, int> last;
        int count=1;
        for( auto ch:str)
        {
            int newCount = 2*count;
            if(last.find(ch)!=last.end())
                newCount -= last[ch];
            last[ch] = count;
            count = newCount;
        }
        return count;
    }
    string betterString(string str1, string str2) {
        // code here
        int count1 = distinctSubsequence(str1);
        int count2 = distinctSubsequence(str2);
        return count1 >= count2 ? str1 : str2;
    }
};
