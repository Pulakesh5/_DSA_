// SC:O(n) and TC: O(n)
class Solution{   
public:
    int findMaxAverage(int arr[], int n, int k) {
        long long pre[n+1];
        pre[0]=0;
        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+arr[i];
        double avg=INT_MIN,sum=0;
        int index=k;
        for(int i=k;i<=n;i++){
            sum=pre[i]-pre[i-k];
            if(sum/k > avg){
                index=i;
                avg=sum/k;
            }
        }
        return index-k;
    }
};
//SC: O(1) && TC : O(n)
class Solution{   
public:
    int findMaxAverage(int arr[], int n, int k) {
        double sum=0,avg=-999999999;
        int ans=k;
        for(int i=0;i<n;i++){
            if(i<(k-1))
                sum+=arr[i];
            else{
                sum+=arr[i];
                if((sum/k)>avg)
                {
                    avg=sum/k;
                    ans=i-k+1;
                }
                sum-=arr[i-k+1];
            }
        }
        return ans;
    }
};
