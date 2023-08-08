class Solution {
public:
    int findRotation(vector<int> &nums)
    {
        int mid, len = nums.size();
        // int l=1, r=len-1;
        // while(l<r)
        // {
        //     mid = l+(r-l)/2;
        //     cout<<mid<<' ';
        //     if(nums[mid-1]>nums[mid])
        //         return mid;
        //     if(nums[mid]<nums[len-1])
        //         r = mid-1;
        //     else if(nums[mid]>nums[len-1])
        //         l = mid+1;
        // }
        // cout<<endl;
        // return (nums[l-1]>nums[l] ? l: -1);
        for(int i=1; i<len; i++)
        {
            if(nums[i-1]>nums[i])
                return i;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int index = findRotation(nums);
        // cout<<index<<endl;

        int binSearchIndex, len = nums.size();
        if(index==-1)
        {
            binSearchIndex = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            if(binSearchIndex==len || (nums[binSearchIndex]>target))
                return -1;
            return binSearchIndex;
        }

        binSearchIndex = lower_bound(nums.begin(),nums.begin()+index, target) - nums.begin();
        cout<<"first "<<binSearchIndex<<endl;
        if(nums[binSearchIndex]==target)
            return binSearchIndex;
        
        binSearchIndex = lower_bound(nums.begin()+index,nums.end(), target) - nums.begin();
        cout<<"second "<<binSearchIndex<<endl;
        if(binSearchIndex!=len && nums[binSearchIndex]==target)
            return binSearchIndex;
        
        return -1;


    }
};
