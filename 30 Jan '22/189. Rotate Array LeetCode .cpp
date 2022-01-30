//Think about reversing the whole or partial array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k= k%n;
        rotat(nums, 0, n-1);
        rotat(nums, 0, k-1);
        rotat(nums, k, n-1);
    }
    void rotat(vector<int> &nums, int start, int end){
        while(start<end){
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;end--;
        }
    }
    
};
