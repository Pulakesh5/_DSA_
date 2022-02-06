// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// compare with the sorted array, you will find a cycle of elements which together can sort some of the array positions.
// required operations for each cycle would be cycle_size-1 (observation)
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=nums.size();
	    pair<int,int> pos[n];
	    
	    for(int i=0;i<n;i++){
	        pos[i].first=nums[i];
	        pos[i].second=i;
	    }
	    sort(pos,pos+n);
	    vector<bool> vis(n,false);
	   // memset(vis,0,sizeof(false));
	    int ans=0;
	    for(int i=0;i<n;i++){
	        if(vis[i] || pos[i].second==i) continue;
	        
	        int j=i,cycle=0;
	        
	        while(!vis[j]){
	            vis[j]=true;
	            j=pos[j].second;
	            cycle++;
	        }
	        //cout<<cycle<<'\n';
	        ans+=max(cycle-1,0);
	    }
	    return ans;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
