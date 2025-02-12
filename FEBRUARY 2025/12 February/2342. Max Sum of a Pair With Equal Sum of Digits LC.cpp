class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<pair<int,int>> digitSum(105, make_pair(-1,-1));
        for(int num:nums)
        {
            int sum = 0, aux = num;
            while(aux)
            {
                sum += (aux%10);
                aux /=10;
            }
            if(digitSum[sum].first<num)
            {
                digitSum[sum].second = digitSum[sum].first;
                digitSum[sum].first = num;
            }
            else if(digitSum[sum].second<num)
                digitSum[sum].second = num;
        }
        int maxSum = -1;
        for(int i=1; i<digitSum.size(); i++)
        {
            if(digitSum[i].first!=-1 && digitSum[i].second!=-1)
            {
                maxSum = max(maxSum, digitSum[i].first+digitSum[i].second);
            }
        }
        return maxSum;
    }
};
