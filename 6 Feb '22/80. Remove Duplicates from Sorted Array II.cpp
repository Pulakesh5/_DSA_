//think of working with the cluster of same number and try to use two pointer 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int front,rear;
        front=0; rear=0;
        int ans=0,j=0;
        while(front<n && rear<n){
            if(nums[front]!=nums[rear]){
                nums[j++]=nums[front];
                front++;
                rear++;
                ans+=1;
                continue;
            }
            else{
                while(rear<n && nums[rear]==nums[front]){
                rear++;
                }
                int d=min(rear-front,2);
                //cout<<rear<<" "<<front<<" "<<d;
                ans+=d;
                for(int i=0;i<d;i++)
                    nums[j++]=nums[front];
                front=rear;
            }
        }
        return ans;
    }
};
