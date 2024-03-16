class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        map<int,int> sumPos;
        sumPos[0] = -1;
        int maxLen = 0;
        for(int i=0; i<size; i++)
        {
            sum+=(nums[i]==0?-1:1);
            if(sumPos.find(sum)!=sumPos.end())
                maxLen = max(maxLen, i-sumPos[sum]);
            else
                sumPos[sum] = i;
        }
        return maxLen;
    }
};
