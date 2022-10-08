class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        for(int it:nums) cout<<it<<" ";
        cout<<endl;
        int num1,n=nums.size(),left,right;
        int sum=0;
        int closestSum=100005,diff;
        closestSum=(target<0?100005:-100005);
        for(int i=0;i<(n-2);i++)
        {
            num1=nums[i];
            left=i+1;
            right=n-1;
            while(left<right)
            {
                sum=num1+nums[left]+nums[right];
            
                if((target-sum)==0)
                    return target;
                else if(target>sum)
                {
                    left++;
                }
                else
                {
                    right--;
                }
                if(abs(target-closestSum)>abs(target-sum))
                {
                    // cout<<closestSum<<" "<<sum<<" [ "<<num1<<", "<<nums[left]<<", "<<nums[right]<<"]\n";
                    closestSum=sum;
                    
                }
            }
        }
        
        return closestSum;
    }
};
