class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int l=0,r=0;
        long long sum=0;
        while(r<n){
            sum+=arr[r++];
            //cout<<sum<<" "<<l<<" "<<r<<endl;
            while(l<r && sum>s){
                sum-=arr[l++];
                //cout<<sum<<" "<<l<<" "<<r<<endl;
            }
            if(s!=0 && sum==s)
            return {l+1,r};
        }
        return {-1};
    }
};
