class Solution {
public:
    bool divisorGame(int n) {
        return ((n%2)==0);
        // if n is even alice will win, otherwise loose
        // proof: 
            // if n is even, we can choose x=1 and make her loose by considering the odd case
            // if n is odd, we can only choose a odd number x, and giving her n-x as even which lets her win 

    }
};
