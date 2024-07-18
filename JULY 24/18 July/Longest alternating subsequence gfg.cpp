class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        int N = arr.size();
        int inc = 1, dec = 1;
        for(int i=1; i<N; i++)
        {
            if(arr[i]>arr[i-1])
                inc = dec+1;
            else if(arr[i]<arr[i-1])
                dec = inc+1;
        }
        return max(inc, dec);
    }
};
