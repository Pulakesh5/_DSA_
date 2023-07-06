class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int minLength = len+1, subArraySum = 0, subLength = 0;
        for(int i = 0; i<len; i++)
        {
            if((subArraySum+nums[i])<=target)
            {
                subLength++;
                subArraySum+=nums[i];
                continue;
            }
            if(subArraySum>=target)
            {
                // cout<<i<<" "<<subArraySum<<" "<<subLength<<endl;
                minLength = min(minLength, subLength);
            }
            while(subArraySum>=target && subLength)
            {
                minLength = min(minLength, subLength);
                subArraySum -= nums[i-subLength];
                subLength--;
                // cout<<i<<" "<<subArraySum<<" "<<subLength<<endl;
            }
            subArraySum+=nums[i];
            subLength++;
        }
        // cout<<"Outer loop :\n";
        while(subArraySum>=target && subLength)
        {
            minLength = min(minLength, subLength);
            // cout<<len-1<<" "<<subArraySum<<" "<<subLength<<endl;
            subArraySum -= nums[len-subLength];
            subLength--;
        }
        cout<<"\n\n";
        if(minLength==(len+1))
            return 0;
        return minLength;
    }
};
// 1 2 3 4 5
