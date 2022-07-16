class Solution{
  public:
    int totalSum;
    void backtrack(int a[], int n,int k,int count,int sum, bool &ans){
        if(count == k-1){
            ans=true;
            return;
        }
        if(sum>(totalSum/k)) return;
        if(sum==(totalSum/k)){
             backtrack(a,n,k,count+1,0,ans);
             if(ans) return;
        }
        int copy;
        for(int i=0;i<n;i++){
            if(a[i]!=-1){
                copy=a[i];
                a[i]=-1;
                backtrack(a,n,k,count,sum+copy,ans);
                if(ans){
                    return;
                }
                a[i]=copy;
            }
        }
    }
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
        if(k==1) return true;
        totalSum=0;
        for(int i=0;i<n;i++) totalSum+=a[i];
        
        if((totalSum%k)!=0) return false;
        
        bool ans=false;
        backtrack(a,n,k,0,0,ans);
        return ans;
    }
};
