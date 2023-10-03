class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> count(101,0);
        for(int num:nums)
            count[num]++;
        int pairs = 0;
        for(int i=1; i<=100; i++)
            pairs+=(count[i]*(count[i]-1))/2;
        return pairs;
    }
};
