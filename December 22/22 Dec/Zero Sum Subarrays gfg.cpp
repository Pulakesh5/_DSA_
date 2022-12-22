    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        unordered_map<long long , int> freq;
        freq[0]++;
        long long ans=0, sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            freq[sum]++;
            ans+=(freq[sum]-1);
        }
        return ans;
    }
