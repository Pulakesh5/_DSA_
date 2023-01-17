class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int n=s.size();
        int tillNowOne=0;
        int flip=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                flip ++;
                flip = min(flip, tillNowOne);
            }
            else
                tillNowOne++;
        }
        return flip;
    }
};
