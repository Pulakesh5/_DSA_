class Solution {
public:
    bool backtrack(string &str, int index, int num)
    {
        if(num<0)
            return false;
        int len = str.size();
        if(index>=len && num==0)
            return true;
        int sum = 0;
        for(int i=index; i<len; i++)
        {
            sum = sum*10 + (str[i]-'0');
            if(backtrack(str, i+1, num-sum))
                return true;
        }
        return false;
    }
    bool check(int num)
    {
        int sq = num*num;
        string sq_str = to_string(sq);
        return backtrack(sq_str, 0, num);
    }
    int punishmentNumber(int n) {
        int punishment_number = 0;
        for(int i=1; i<(n+1); i++)
        {
            if(check(i))
            {
                punishment_number += i*i;
                // cout<<"matched "<<i<<endl;
            }
        }
        return punishment_number;
    }
};
