//bitset approach
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> st;
        vector<vector<int>> ans;
        ans.push_back({});
        for(int i=1;i<(1<<n);i++){ //generating all possible numbers of length n
            bitset<10> bs(i);  // bitset of those numbers
            vector<int> t;
            for(int j=0;j<n;j++){ // making array according to that bitset
                if(bs[j]==1)
                    t.push_back(nums[j]);
            }
            st.insert(t);
        }
        for(auto it:st)
            ans.push_back(it);
        return ans;
    }
};
