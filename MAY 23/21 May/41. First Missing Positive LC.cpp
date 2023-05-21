class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i]<0)
                nums[i] = 0;
        }
        int index;
        for(int i=0; i<n; i++)
        {
            index = abs(nums[i]);
            index--;
            if(index>=0 && index<n)
            {
                if(nums[index]>0)
                    nums[index] *= -1;
                else if(nums[index] == 0)
                    nums[index] = -1*(n+1);
            }
        }
        for(int i=0;i<n;i++)
            cout<<nums[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
            if(nums[i]>=0)
                return (i+1);
        return n+1;
    }
};
