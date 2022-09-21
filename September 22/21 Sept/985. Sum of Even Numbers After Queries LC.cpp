class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int evenSum=0,n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if((nums[i]%2)==0)
                evenSum+=nums[i];
        }
        
        vector<int> evenSums;
        int q=queries.size(),add,pos;
        bool even;
        //cout<<(-3%2);
        
        for(int i=0;i<q;i++)
        {
            pos=queries[i][1];
            add=queries[i][0];
            even=!(nums[pos]);
            
            if(!(nums[pos]%2))
            {
                if((add%2)==0)
                    evenSum+=add;
                else
                    evenSum-=nums[pos];
            }
            else if(nums[pos]%2 && (add%2))
                evenSum+=(add+nums[pos]);
            
            evenSums.push_back(evenSum);
            nums[pos]+=add;
        }
        
        return evenSums;
    }
};
