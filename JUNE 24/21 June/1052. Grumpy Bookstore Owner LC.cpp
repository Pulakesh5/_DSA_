class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int len = customers.size();
        vector<int> preSum(len+1);
        vector<int> nonGrumpySum(len+1);
        for(int i=0; i<len; i++)
        {
            preSum[i+1] = preSum[i] + customers[i];
            nonGrumpySum[i+1] = nonGrumpySum[i];
            if(grumpy[i]==0)
            {
                nonGrumpySum[i+1] += customers[i];
            }
        }
        int window, rest, maxSatisfiedCustomer=0;
        // for(int i=0; i<len; i++)
        //     cout<<preSum[i+1]<<" ";
        // cout<<endl;
        // for(int i=0; i<len; i++)
        //     cout<<nonGrumpySum[i+1]<<" ";
        // cout<<endl;
        for(int i=minutes; i<=len; i++)
        {
            window = (preSum[i]-preSum[i-minutes]);
            rest = (nonGrumpySum[len]-nonGrumpySum[i] + nonGrumpySum[i-minutes]);
            // cout<<i<<" : "<<window<<", "<<rest<<endl;
            maxSatisfiedCustomer = max(maxSatisfiedCustomer, window+rest);
        }
        return maxSatisfiedCustomer;
    }
};
