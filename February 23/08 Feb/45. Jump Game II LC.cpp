class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        int curMax=0,i=0,nextMax=0;
        int level=0;
        while(i<=curMax){
            nextMax=curMax;
            for(;i<=curMax;i++){
                nextMax=max(nextMax,nums[i]+i);
                if(nextMax>= (n-1)) return level+1;
            }
            level++;
            curMax=nextMax;
        }
        return -1;
    }
};
