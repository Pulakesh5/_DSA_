class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> modCount;
        modCount[0] = 1;
        long long sum=0, subArrayCount=0, len = nums.size();
        for(int i=0; i<len; i++)
        {
            sum+=nums[i];
            sum = (sum%k+k)%k;
            subArrayCount+=(modCount[sum]);
            // cout<<nums[i]<<" : "<<modCount[sum]<<", "<<subArrayCount<<endl;
            modCount[sum]++;
        }
        return subArrayCount;
    }
    // 0, 4, 4, 4, 2, 4, 0
};
