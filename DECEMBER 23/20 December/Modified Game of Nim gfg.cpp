class Solution{
public:
    int findWinner(int n, int A[]){
        // code here
        int xorAll=0;
        for(int i=0; i<n; i++)
            xorAll^=A[i];
        if(xorAll==0)
            return 1;
        // we need to check cnt = #elements with odd occurence(consider only 1 element)
        
        // if cnt is odd then player 2 wins
        // if cnt is even player 1 wins
        
        // we dont need to think of elements with even occurence
        // so if n is odd -> cnt is odd
        //   if n is even -> cnt is even
        if(n%2)
            return 2;
        else
            return 1;
    }
};
