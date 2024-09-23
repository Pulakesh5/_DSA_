class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long N = arr.size();
        long long sumOfN = N*(N+1)/2, sum = 0; 
        sort(arr.begin(), arr.end());
        vector<int> wantedNumbers(2, -1);
        for(int i=0; i<(N-1); i++)
        {
            // cout<<i<<" "<<arr[i]<<", ";
            sum += arr[i];
            if(arr[i]==arr[i+1])
                wantedNumbers[0] = arr[i];
        }
        sum += arr[N-1];
        wantedNumbers[1] = wantedNumbers[0] + (sumOfN-sum);
        return wantedNumbers;
    }
};
