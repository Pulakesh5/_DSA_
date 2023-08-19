{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long sum)
    {
        // Your code here
        long long curr_sum=0;
        int first=1,last=0;
        if(sum<=0) return {-1};
        for(int i=0;i<n;i++){
            //cout<<curr_sum<<" "<<first<<" "<<last<<'\n';
            
            while(curr_sum>sum)
            {
                curr_sum-=arr[first-1];
                first++;
                //cout<<" "<<curr_sum<<" "<<first<<" "<<last<<'\n';
            }
            
            if(curr_sum==sum) return {first,last};
            else if(curr_sum<sum){
                curr_sum+=arr[i];
                last++;
            }
        }
        while(curr_sum>sum)
        {
            curr_sum-=arr[first-1];
            first++;
            //cout<<" "<<curr_sum<<" "<<first<<" "<<last<<'\n';
        }
        if(curr_sum==sum) return {first,last};
        return {-1};
        
    }
};
