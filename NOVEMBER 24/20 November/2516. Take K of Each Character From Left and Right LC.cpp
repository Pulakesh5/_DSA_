class Solution {
public:
    int takeCharacters(string s, int k) {
        size_t len = s.size(), window = k*3;
        if(window > len)
            return -1;

        map<char, int> freq;
        for(char ch:s)
            freq[ch]++;
        if(freq['a']<k || freq['b']<k || freq['c']<k)
            return -1;
        int minWindowSize = len;
        int left = len-1, right = len-1;
        while(left>=0)
        {
            freq[s[left]]--;
            while(freq['a']<k || freq['b']<k || freq['c']<k)
            {
                freq[s[right]]++;
                right--;
            }
            if((len-(right-left+1))<minWindowSize)
                minWindowSize = (len-(right-left+1));
            left--;
        }
        return minWindowSize;
    }
};
