class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int N = arr1.size();
        // int l1=0, r1=N-1, mid1;
        // int l2=0, r2=N-1, mid2;
        vector<int> merged(N+1);
        int k=0, i=0, j=0;
        while(i<N && j<N && k<=N)
        {
            if(arr1[i]<=arr2[j])
                merged[k] = arr1[i++];
            else 
                merged[k] = arr2[j++];
            k++;
        }
        
        while(i<N && k<=N)
            merged[k++] = arr1[i++];
        
        while(j<N && k<=N)
            merged[k++] = arr2[j++];
        
        return merged[N-1]+merged[N];
        
    }
};
