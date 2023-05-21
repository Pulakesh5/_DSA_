class Solution {
public:
    int binarySearch(vector<int> &nums, int l, int r, int target)
    {
        int mid;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int index = -1;
        for(int i=0; i<(n-1); i++)
        {
            if(nums[i]>nums[i+1])
            {
                index = i;
                break;
            }
        }
        if(index!=-1)
        {
            int index1 = binarySearch(nums, 0, index, target);
            if(index1 != -1) return index1;
            int index2 = binarySearch(nums, index+1, n-1, target);
            if(index2 != -1) return index2;
            return -1;
        }

        return binarySearch(nums, 0, n-1, target);
    }
};
