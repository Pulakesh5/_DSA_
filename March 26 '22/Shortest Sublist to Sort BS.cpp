int solve(vector<int>& nums) {
    vector<int> dummy(nums.begin(),nums.end());
    sort(dummy.begin(),dummy.end());
    int i=0,j=nums.size()-1;
    while(i<j){
        if(nums[i]==dummy[i]) i++;
        if(nums[j]==dummy[j]) j--;
        if(nums[i]!=dummy[i] && nums[j]!=dummy[j]) break;
    }
    if(i>=j) return 0;
    return (j-i)+1;
}
