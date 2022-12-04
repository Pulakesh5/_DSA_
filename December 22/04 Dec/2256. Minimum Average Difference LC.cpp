class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long  sum=0;

        for(int i=0;i<n;i++) 
            sum+=nums[i];

        long long prefixSum=0,suffixSum=sum;

        long long minAvg = INT_MAX, minPos=0;
        long long prevAvg=0, sufAvg=0;

        for(int i=0;i<n;i++)
        {
            prefixSum+=nums[i];
            
            prevAvg = prefixSum/(i+1);

            suffixSum-=nums[i];

            if((n-1-i)>0)
                sufAvg = suffixSum/(n-1-i);
            else
                sufAvg=0;
            
            if(abs(prevAvg-sufAvg)<minAvg)
            {
                minAvg = abs(prevAvg - sufAvg);
                minPos = i;
            }
        }
        
        return minPos;
    }
};
