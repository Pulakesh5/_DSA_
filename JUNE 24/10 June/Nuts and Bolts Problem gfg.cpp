class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        
        sort(nuts, nuts+n);
        sort(bolts, bolts+n);
    }
    // nuts = {7, 3, 2, 1, 8}
    // bolts = {3, 7, 1, 2, 8}
};
