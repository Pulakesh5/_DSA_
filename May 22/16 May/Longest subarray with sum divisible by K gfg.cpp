class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    long long sum=0;
	    int length=0;
	    map<int,int> mp;
	    long long curr=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        curr=((sum%k)+k)%k;
	        if(curr==0) length=i+1;
	        else if(mp.find(curr)==mp.end()) mp[curr]=i;
	        else length=max(length,i-mp[curr]);
	    }
	    return length;
	    
	}
};
