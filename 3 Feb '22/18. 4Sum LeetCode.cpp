class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        if(n<4) return ans;
        
        for(int i=0;i<n-3;i++){
            
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(0ll+nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(0ll+nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            
            for(int j=i+1;j<n-2;j++){
                
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(0ll+nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(0ll+nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                
                int l=j+1,r=n-1;
                while(l<r){
                    long sum=nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum==target){
                        ans.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                        do{l++;}while(nums[l]==nums[l-1]&& l<r);
                        do{r--;}while(nums[r]==nums[r+1]&& l<r);
                    }
                    else if(sum<target)
                        l++;
                    else
                        r--;
                    
                    
                }
            }
        }
        
        return ans;
        
        
    }
    
};
