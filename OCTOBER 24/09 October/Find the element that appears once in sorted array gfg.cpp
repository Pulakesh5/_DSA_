class Solution
{
  public:
    int findOnce(int arr[], int n) {
        //code here.
        if(n==1)
            return arr[0];
        for (int i=0; i+1<n; i+=2) {
            if(arr[i]!=arr[i+1])    
                return arr[i];
        }
        return arr[n-1];
    }
};
