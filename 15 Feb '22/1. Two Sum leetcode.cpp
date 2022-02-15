//First approach(my)
//TC: O(nlogn) for sorting
//SC: O(2n) for storing pairs
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++)
            vp[i]={nums[i],i};
        sort(vp.begin(),vp.end());
        int l=0,r=n-1;
        vector<int> ans;
        while(l<r){
            int num1=vp[l].first,num2=vp[r].first;
            int sum=num1+num2;
            if(sum==target){
                ans.push_back(vp[l].second);
                ans.push_back(vp[r].second);
                break;
            }
            if(sum<target)
                l++;
            else
                r--;
        }
        return ans;
    }
};

//Second approach
//TC: O(n) only one pass
//SC: O(2n) for worst case otherwise it is always better ig 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> index;
        for(int i=0;i<n;i++){
            if(index.find(target-nums[i])!=index.end()){
                return {index[target-nums[i]],i};
            }
            index[nums[i]]=i;
        }
        return {};
    }
};
