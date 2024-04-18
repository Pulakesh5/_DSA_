class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
        int MOD = n+5;
        int element;
        for(int i=0; i<(n+2); i++)
        {
            element = (arr[i]%MOD) - 1;
            arr[element] += MOD;
        }
        vector<int> repeatedNumbers;
        for(int i=n+1; i>=0; i--)
        {
            if(arr[(arr[i]%MOD)-1]/MOD==2)
            {
                // cout<<arr[i]%MOD<<" "<<i<<endl;
                if(repeatedNumbers.size() && repeatedNumbers.back()==(arr[i]%MOD))
                    continue;
                repeatedNumbers.push_back(arr[i]%MOD);
            }
            if(repeatedNumbers.size()==2)
                break;
        }
        reverse(repeatedNumbers.begin(), repeatedNumbers.end());
        return repeatedNumbers;
    }
};
