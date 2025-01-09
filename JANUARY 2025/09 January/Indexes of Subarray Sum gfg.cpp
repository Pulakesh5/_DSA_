class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        map<int,int> prefix;
        prefix[0] = 0;
        int N = arr.size(), sum=0;
        for(int i=0; i<N; i++)
        {
            sum += arr[i];
            if(prefix.find(sum-target)!=prefix.end())
            {
                return {prefix[sum-target]+1, i+1};
            }
            if(prefix.find(sum)==prefix.end())
                prefix[sum] = i+1;
        }
        return {-1};
    }
};
