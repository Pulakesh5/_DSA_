//  TC: O(nlogn) for sorting
//  SC: O(n)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        //map<long long, int> freq;
        sort(nums.begin(), nums.end());
        set<int> st,used;
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(used.find(nums[i])==used.end() && st.find(nums[i]-k)!=st.end() ){
                ans++;
                st.erase(nums[i]-k);
                used.insert(nums[i]);
            }  
            st.insert(nums[i]);
        }
        return ans;
    }
};
