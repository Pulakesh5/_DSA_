//  Simple question sliding window technic, 
//  practice writing syntax free submissble code in one go
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long sum=0;
        
        for(int i=0;i<k;i++)
            sum+=arr[i];
        
        int i=0,j=k,n=arr.size();
        
        int ans=0;
        
        if(sum/k >= threshold)
                ans++;
        
        while(j<n){
            
            sum-=arr[i++];
            
            sum+=arr[j++];
            
            if(sum/k >= threshold)
            {
                ans++;
            }
        }
        return ans;
    }
};
