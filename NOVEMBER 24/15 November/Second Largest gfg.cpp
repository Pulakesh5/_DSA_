class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        set<int> st(arr.begin(), arr.end());
        if(st.size()<2)
            return -1;
        auto it = st.end();
        it--;
        it--;
        return *it; 
    }
};
