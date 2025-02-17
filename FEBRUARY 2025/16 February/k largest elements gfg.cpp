class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        sort(arr.begin(), arr.end());
        
        vector<int> k_largest(k);
        
        for(int i=arr.size()-k, j=k-1; j>=0; i++, j--)
            k_largest[j] = arr[i];
        
        return k_largest;
    }
};
