class Solution {
public:
    int check(vector<int> &weights, int capacity)
    {
        int days=0, total=0;
        for(int weight:weights)
        {
            if(total+weight<=capacity)
                total+=weight;
            else
            {
                days++;
                total=weight;
            }
        }
        days+=1;
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sumOfWeight=0;
        for(int weight:weights)
            sumOfWeight+=weight;
        int l = *max_element(weights.begin(),weights.end()), r = sumOfWeight;
        int ans=INT_MAX, capacity, val;
        while(l<=r)
        {
            capacity =(r+l)/2;
            val = check(weights,capacity);
            //cout<<capacity<<" : "<<val<<endl;
            if(val<=days)
            {
                ans = min(ans,capacity);
                r = capacity-1;
            }
            else
                l = capacity+1;
            
        }

        return ans;
    }
};
