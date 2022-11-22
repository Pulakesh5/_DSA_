class Solution{
	public:
	int countTriplets(vector<int>nums){
    if (nums.size() < 3) return 0;
        
    int count = 0;
    int left = 0, right = 0;
    
    for (int i = 1; i < nums.size() - 1; i++) {
        
        left = 0; right = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            
            if (i < j && nums[i] < nums[j]) left++;
            else if (j < i && nums[j] < nums[i]) right++;
            
            }  
            
            count += left * right;
        }
    
    return count;
    
	}
};
