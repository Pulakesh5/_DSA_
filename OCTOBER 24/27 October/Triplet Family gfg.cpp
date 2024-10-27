class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        sort(arr.begin(), arr.end());
        int len = arr.size(), sum, ind;
        for(int i=0; i<(len-1); i++)
        {
            for(int j=i+1; j<len; j++)
            {
                sum = arr[i]+arr[j];
                ind = lower_bound(arr.begin()+j+1, arr.end(), sum) - arr.begin();
                if(ind<len && arr[ind] == sum)
                    return true;
            }
        }
        return false;
    }
};
