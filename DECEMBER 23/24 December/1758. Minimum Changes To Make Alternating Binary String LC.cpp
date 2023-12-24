class Solution {
public:
    int minOperations(string s) {
        int cost1=0, cost2=0, len = s.size();
        for(int i=0; i<len; i++)
        {
            if((i%2)==(s[i]-'0'))
                cost1++;
            else
                cost2++;
        }
        return min(cost1, cost2);
    }
};
