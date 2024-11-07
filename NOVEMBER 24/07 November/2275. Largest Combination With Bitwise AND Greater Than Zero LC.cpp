class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCount(32,0);
        for(int candidate:candidates)
        {
            int k=0;
            while(candidate)
            {
                bitCount[k++] += (candidate%2);
                candidate/=2;
            }
        }
        int largestSize = 0;
        for(int i=31; i>=0; i--)
        {
            // cout<<i<<" : "<<bitCount[i]<<" "<<largestSize<<endl;
            if(bitCount[i] && bitCount[i]>largestSize)
                largestSize = bitCount[i];
        }
        return largestSize;
    }
// TC: 1
//     10000
//     10001
//   1000111
//    111110
//      1100
//     11000
//      1110 
};
