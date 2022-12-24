class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int N){
      //Code here.
      int p=0,n=0;
      long long ans=0,change;
      while(true)
      {
          while(p<N && arr[p]<=0) p++;
          while(n<N && arr[n]>=0) n++;
          
          if(p==N || n==N) break;
          
          change=min(arr[p],-arr[n]);
          
          ans+=(change*abs(p-n));
          
          arr[p]-=change;
          arr[n]+=change;
      }
      
      return ans;
  }
};
