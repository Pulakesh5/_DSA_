  int smallestSumSubarray(vector<int>& a){
      //Code here
      int n=a.size();
      long long sum=0,maxSum=INT_MIN;
      
      for(int i=0;i<n;i++)
      {
        if(a[i]>=0)
            sum-=a[i];
        else
            sum+=(-1*a[i]);
        maxSum=max(sum,maxSum);
        sum=max(0ll,sum);
      }
      return -1*maxSum;
  }
