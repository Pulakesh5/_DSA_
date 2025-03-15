class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int N = nums.size();
        int low = *min_element(nums.begin(), nums.end()), high = *max_element(nums.begin(), nums.end());
        int minCap = high+5, cap;
        while(low<=high)
        {
            cap = (low+high)/2;
            int count = (nums[0]<=cap);
            int picked = count;
            // cout<<low<<" "<<high<<" "<<cap<<" : "<<count<<endl;
            for(int i=1; i<N; i++)
            {
                if(!picked && nums[i]<=cap)   
                {
                    count++;
                    picked = 1;
                }
                else
                    picked = 0;
                // cout<<"\t"<<i<<" "<<count<<" "<<picked<<endl;
            }
            // cout<<count<<"\n\n";
            
            if(count<k)
                low = cap+1;
            else
            {
                high = cap-1;
                minCap = min(minCap, cap);
            }
        }
        return minCap;
    }
};
