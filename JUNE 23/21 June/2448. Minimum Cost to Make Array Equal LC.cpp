class Solution {
public:
    long long calc(vector<int>&nums, vector<int>& cost, long long median){

        long long ans = 0;

         for(int i=0;i<nums.size();i++)
           ans += abs(1ll*nums[i]-median)*(1ll*cost[i]);

         return ans;  
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // int n = nums.size();
        // if(n==1)
        //     return 0;
        // vector<pair<int,int>> vp(n);
        // for(int i=0; i<n; i++)
        //     vp[i] = {nums[i],cost[i]};
        // sort(vp.begin(), vp.end());
        
        // vector<long long> preCost(n+3), sufCost(n+3), sum(n+3);
        // sum[0] = vp[0].second;
        // preCost[0] = 0;
        // //sum[i] contains cumulative sum of cost to change prev i-1 elements by 1
        // for(int i=1; i<n; i++)
        // {
        //     sum[i+1] = sum[i] + cost[i];
        //     preCost[i+1] = preCost[i] + (vp[i].first - vp[i-1].first)*sum[i]*i;
        // }
        
        // sufCost[n] = 0;
        // for(int i=n-2; i>=0; i--)
        // {
        //     sufCost[i+1] = sufCost[i+2] + (vp[i+1].first - vp[i].first)*(sum[n-1]-sum[i+1])*(n-1-i);
        // }
        
        // long long minCost = INT_MAX, currentCost;
        // for(int i=1; i<(n-1); i++)
        // {
        //     currentCost = preCost[i];
        //     currentCost += (sufCost[i+2]+preCost[i]);
        //     currentCost += (i*(vp[i].first-vp[i-1].first)*sum[i]);
        //     currentCost += ((n-1-i)*(vp[i+1].first-vp[i].first)*(sum[n]-sum[i]));
        //     minCost = min(minCost, currentCost);
        // }
        // return minCost;
        long long tot = 0;
        long long sum = 0;
        int n = nums.size();

        vector<pair<int,int>> vec;

        for(int i=0;i<nums.size();i++)
            vec.push_back({nums[i],cost[i]});

        sort(vec.begin(),vec.end());

        for(int i=0;i<n;i++)
        sum += vec[i].second;

        long long median;
        int i=0;

        while(tot < (sum+1)/2 && i<n){

             tot += 1ll*vec[i].second;
             median = vec[i].first;
             i++;
        }    
        
        
        return calc(nums,cost,median);
    }
};
