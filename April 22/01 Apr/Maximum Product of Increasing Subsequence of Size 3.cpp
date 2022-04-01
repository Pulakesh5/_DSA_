class Solution{
  public:
    vector<int> maxProductSubsequence(int *arr , int n) 
    { 
        // Complete the function
        int dp[n+1];
        dp[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i]=max(dp[i+1],arr[i]);
        }
        vector<int> ans;
        set<int> s;
        s.insert(arr[0]);
        long long mul=1;
        for(int i=1;i<(n-1);i++){
            int second=arr[i],third=dp[i+1];
            
            auto it=s.lower_bound(arr[i]);
            
            if(it==s.begin()){
                s.insert(arr[i]);
                continue;
            }
            
            it--;
            int first=*it;
            s.insert(arr[i]);
            
            if(first<second && second<third){
                long long cur=first*1ll*second*1ll*third;
                if(cur>=mul){
                    mul=cur;
                    ans={first,second,third};
                }
            }
        }
        if(ans.empty()) ans.push_back(-1);
        return ans;
    } 

};
