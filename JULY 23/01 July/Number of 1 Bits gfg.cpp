class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        int setBitCount = 0;
        while(N)
        {
            setBitCount +=(N%2);
            N/=2;
        }
        return setBitCount;
    }
};
