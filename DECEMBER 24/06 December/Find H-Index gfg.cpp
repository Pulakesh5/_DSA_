class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        sort(citations.begin(), citations.end());
        int hIndex = 0;
        int low = 0, high = citations.back(), index;
        int N = citations.size();
        while(low<=high)
        {
            index = (low+high)/2;
            int lb = lower_bound(citations.begin(), citations.end(), index) - citations.begin();
            if(N-lb>=index)
            {
                low = index+1;
                hIndex = max(hIndex, index);
            }
            else
            {
                high = index-1;
            }
        }
        return hIndex;
    }
};
