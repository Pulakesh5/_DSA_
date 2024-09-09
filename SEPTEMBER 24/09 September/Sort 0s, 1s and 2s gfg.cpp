class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        int zero = 0, one = 0, two = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i]==0)
                zero++;
            else if(arr[i]==1)
                one++;
            else
                two++;
        }
        int k = 0;
        while(zero--)
            arr[k++] = 0;
        while(one--)
            arr[k++] = 1;
        while(two--)
            arr[k++] = 2;
    }
};
