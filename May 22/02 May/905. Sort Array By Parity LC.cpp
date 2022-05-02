class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        
        for(;j<n;j++){
            if(nums[j]%2==0) swap(nums[i++],nums[j]);
        }
        
        return nums;
        
    }
};

///////////////////////////////////////////////////////

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        queue<int> odd,even;
        for(int i=0;i<n;i++){
            if(nums[i]%2) odd.push(nums[i]);
            else even.push(nums[i]);
        }
        int i=0;
        while(!even.empty()){
            int it=even.front();
            even.pop();
            nums[i++]=it;
        }
        while(!odd.empty()){
            int it=odd.front();
            odd.pop();
            nums[i++]=it;
        }
        return nums;
    }
};
