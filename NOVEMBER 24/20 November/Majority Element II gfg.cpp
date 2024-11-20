class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        vector<int> majorities;
        sort(arr.begin(), arr.end());
        size_t len = arr.size();
        int i = 0, count = 0;
        while(i<len)
        {
            int index = i;
            while(index<len && arr[index]==arr[i])
                index++;
            if((index-i)>(len/3))
                majorities.push_back(arr[i]);
            i = index;
        }
        return majorities;
    }
};
