class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size();
        vector<int> sameParityCount(N);
        for(int i=1; i<N; i++)
        {
            sameParityCount[i] = sameParityCount[i-1];
            if(nums[i]%2 == nums[i-1]%2)
                sameParityCount[i]++;
        }

        vector<bool> answers;
        for(auto q:queries)
        {
            answers.push_back(sameParityCount[q[0]] == sameParityCount[q[1]]);
        }
        return answers;
    }
};
