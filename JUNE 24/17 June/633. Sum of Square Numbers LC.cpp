class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<=1)
            return true;
        int a, b;
        for(a=0; a<=sqrt(c); a++)
        {
            b = sqrt(c-a*a);
            if((a*a+b*b)==c)
                return true;
        }
        return false;
    }
};
