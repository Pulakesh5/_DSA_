class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        unordered_map<int, int> freq;
        for(int num:nums)
            freq[num]++;
        vector<int> maj;
        int N = nums.size();
        for(auto &it:freq)
        {
            if(it.second>(N/3))
                maj.push_back(it.first);
        }
        sort(maj.begin(), maj.end());
        if(maj.size()==0)
            maj.push_back(-1);
        return maj;
    }
};
