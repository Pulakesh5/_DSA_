class Solution {
public:
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> ans;
        int start=0,end=nums.size()-1;
        solve(ans,nums,start,end);
        
        return ans;
    }
 
    void solve(vector<int> &ans, vector<int> &nums, int start, int end){
        if(start<=end){
            int mid=(start+end)/2;
            ans.push_back(nums[mid]);
            solve(ans, nums, start,mid-1);
            solve(ans, nums, mid+1, end);
        }
    }
};
