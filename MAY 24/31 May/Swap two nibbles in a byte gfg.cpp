class Solution {
  public:
    // 128 64 32 16 8 4 2 1
    int swapNibbles(int n) {
        // code here
        int swappedNibble = 0;
        for(int i=0; i<=3; i++)
        {
            if(n&(1<<i))
                swappedNibble+=(1<<(i+4));
        }
        for(int i=4; i<=7; i++)
        {
            if(n&(1<<i))
                swappedNibble+=(1<<(i-4));
        }
        return swappedNibble;
    }
};
