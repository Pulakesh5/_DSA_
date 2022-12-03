class Solution {
public:
    bool  check(vector<int> &stalls, int k,  int diff)
    {
        int curr=stalls[0], p=1, n=stalls.size();
        
        for(int i=1;i<k;i++)
        {
            int pos=lower_bound(stalls.begin()+p, stalls.end(), curr+diff) - stalls.begin();
            if(pos>=n) return false;
            p=pos+1;
            curr=stalls[pos];
        }
        return true;
    }
    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        sort(stalls.begin(), stalls.end());
        //int n=stalls.size();
        int l=0,r=stalls[n-1]-stalls[0],mid;
        int ans=0;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(check(stalls,k,mid))
            {
                ans=max(ans,mid);
                l=mid+1;
            }
            else
                r=mid-1;
        }
        
        return ans;
    }
    
    
};
