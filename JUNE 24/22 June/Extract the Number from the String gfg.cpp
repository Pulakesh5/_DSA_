class Solution {
  public:
    long long ExtractNumber(string s) {
        int len = s.size();
        vector<long long> extractedNumbers;
        for(int i=0; i<len; )
        {
            if(s[i]>='0' && s[i]<='9')
            {
                long long number = 0;
                bool nine = false;
                while(i<len && s[i]>='0' && s[i]<='9')
                {
                    if(s[i]=='9')
                        nine = true;
                    else
                        number = number*10+(s[i]-'0');
                    i++;
                }
                if(nine)
                    extractedNumbers.push_back(-1);
                else
                    extractedNumbers.push_back(number);
            }
            else
                i++;
        }
        return *max_element(extractedNumbers.begin(), extractedNumbers.end());
    }
};
