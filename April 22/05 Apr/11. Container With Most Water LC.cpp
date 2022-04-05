class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int curr=min(height[left],height[right])*(right-left);
        while(left<right){
            if(height[left]<height[right]){
                left++;
            }
            else 
                right--;

            curr=max(curr,min(height[left],height[right])*(right-left));
        }
        return curr;
    }
};
