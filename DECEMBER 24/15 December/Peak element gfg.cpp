class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
        int N = arr.size();
        if(N==1)
            return 0;
        if(N==2)
        {
            if(arr[0]>=arr[1])
                return 0;
            else
                return 1;
        }
        for(int i=1; i<(N-1); i++)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                return i;
        }
        if(arr[0]>=arr[1])
            return 0;
        if(arr[N-2]<=arr[N-1])
            return N-1;
    }
};
