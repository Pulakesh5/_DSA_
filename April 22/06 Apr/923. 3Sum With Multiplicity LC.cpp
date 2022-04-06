class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mod=1e9+7;
        int ans=0;
        for(int i=0;i<(n-2);i++){
            int l=i+1,r=n-1;
            while(l<r){
                int sum=arr[i]+arr[l]+arr[r];
                if(sum==target){
                    int count1=1,count2=1;
                    while(l<r && arr[l]==arr[l+1]){
                        count1++;
                        l++;
                    }
                    while(l<r && arr[r]==arr[r-1]){
                        count2++;
                        r--;
                    }
                    if(l==r){
                        ans=(ans%mod + (count1%mod * (count1-1)%mod)/2)%mod;
                    }
                    if(l!=r){
                        ans=(ans%mod + (count1%mod * count2%mod)%mod);
                    }
                    l++;r--;
                }
                else{
                    if(sum<target)
                        l++;
                    else
                        r--;
                }
            }
        }
        return ans;
    }
};
