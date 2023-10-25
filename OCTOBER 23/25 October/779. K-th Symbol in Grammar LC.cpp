class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1)
            return 0;
        else if(n==2)
            return k-1;
        else
        {
            if(kthGrammar(n-1,(k+1)/2)==1)
                return k%2;
            else
                return ((k%2 == 0)? 1 : 0);
        }
    }
};


/*
0
01
0110
01101001


*/
