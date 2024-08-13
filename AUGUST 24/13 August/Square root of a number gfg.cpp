class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        long long int sqrtN = 1;
        while(sqrtN*sqrtN<n)
            sqrtN++;
        if(sqrtN*sqrtN>n)
            sqrtN--;
        return sqrtN;
    }
};
