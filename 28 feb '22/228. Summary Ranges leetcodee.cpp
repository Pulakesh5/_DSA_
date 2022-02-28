class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        vector<string> ans;
        for(i=0;i<n;){
            for(j=i+1;j<n;j++){
                if(nums[j]!=nums[j-1]+1)
                    break;
            }
            string s="";
            if(j-i>1)
            {
                s+=to_string(nums[i]);
                s+="->";
                s+=to_string(nums[j-1]);
            }
            else{
                s+=to_string(nums[i]);
            }
            ans.push_back(s);
            i=j;
        }
        return ans;
    }
};
