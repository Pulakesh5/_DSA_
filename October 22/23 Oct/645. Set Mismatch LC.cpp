class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        set<int> st;
        
        int n=nums.size(), repeat;
        long long sum=0, sumn=(1ll*n*(n+1))/2;
        
        for(int num:nums){
            if(st.find(num)!=st.end()){
                repeat=num;
                continue;
            }
            st.insert(num);
            sum+=num;
        }
        return {repeat,(int)(sumn-sum)};
    }
};
