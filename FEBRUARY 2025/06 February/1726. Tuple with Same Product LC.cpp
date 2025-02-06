class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tupleCount = 0;
        unordered_map<int, int> prodCount;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
                prodCount[nums[i]*nums[j]]++;
        }
        for(auto [prod, count]:prodCount)
        {
            tupleCount += 4*(count*(count-1));
        }
        return tupleCount;
    }
};
