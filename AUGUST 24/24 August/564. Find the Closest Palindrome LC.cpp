class Solution {
public:
    string nearestPalindromic(string num) {
        int digits = num.size();
        if(digits == 1)
            return to_string(stoi(num)-1);
        
        
        vector<long> candidates;

        candidates.push_back(pow(10, digits-1) - 1);
        candidates.push_back(pow(10, digits) + 1);

        int midIndex = (digits+1)/2;
        long prefix = stol(num.substr(0, midIndex));

        vector<long> v = {prefix, prefix+1, prefix-1};
        for(long i:v)
        {
            string postfix = to_string(i);
            if(digits%2)
                postfix.pop_back();
            reverse(postfix.begin(), postfix.end());
            string c = to_string(i)+postfix;
            candidates.push_back(stol(c));
        }

        long minDiff = LONG_MAX;
        long result;
        long newNum = stol(num);

        for(int i=0; i<5; i++)
        {
            if(candidates[i]!=newNum && abs(candidates[i]-newNum)<minDiff)
            {
                minDiff = abs(candidates[i]-newNum);
                result = candidates[i];
            }
            else if(abs(candidates[i]-newNum) == minDiff)
                result = min(result, candidates[i]);
        }

        return to_string(result);
    }
};
