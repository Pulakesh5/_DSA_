class Solution {
public:
    int minimumDeletions(string s) {
        int count_a = 0, count_b = 0;
        for(char ch:s)
        {
            if(ch=='a')
                count_a++;
        }
        int minDel = count_a;
        for(char ch:s)
        {
            if(ch=='b')
                count_b++;
            else
                count_a--;

            minDel = min(minDel, count_a+count_b);
        }
        return minDel;
    }
};
