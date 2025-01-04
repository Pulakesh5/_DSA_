class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int count = 0;
        int N = arr.size();
        for(int i=0; i<(N-2); i++)
        {
            int l = i+1, r = N-1, sum;
            while(l<r)
            {
                sum = arr[i] + arr[l] + arr[r];
                if(sum == target)
                {
                    int lc = 1, rc = 1;
                    while(l<r && arr[l]==arr[l+1])
                    {
                        l++;
                        lc++;
                    }
                    while(l<r && arr[r]==arr[r-1])
                    {
                        r--;
                        rc++;
                    }
                    if(l==r)
                        count += (lc*(lc-1))/2;
                    else
                        count += (lc*rc);
                    l++;
                    r--;
                } 
                else if(sum < target)
                    l++;
                else
                    r--;
            }
        }
        return count;
    }
};
