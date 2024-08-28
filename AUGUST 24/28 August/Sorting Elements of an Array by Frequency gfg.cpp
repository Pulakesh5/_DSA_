class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        map<int, int> freq;
        for(int num:arr)
            freq[num]++;
        vector<pair<int,int>> vp;
        for(auto it:freq)
            vp.push_back({it.second, it.first});
        sort(vp.begin(), vp.end(), [](auto a, auto b) {
            if(a.first!=b.first)
                return a.first>b.first;
            return a.second<b.second;
        });
        int k=0;
        for(auto it:vp)
        {
            for(int i=0; i<it.first; i++)
                arr[k++] = it.second;
        }
        return arr;
    }
};
