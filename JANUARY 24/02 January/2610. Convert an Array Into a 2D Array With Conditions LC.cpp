class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> freq;
        for(int num:nums)
            freq[num]++;
        int maxFreq=0;
        for(auto it:freq) maxFreq = max(maxFreq, it.second);
        vector<vector<int>> matrix(maxFreq);
        for(auto it:freq)
        {
            int num = it.first, count = it.second;
            while(count)
                matrix[--count].push_back(num);
        }
        return matrix;
    }
};
