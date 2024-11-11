class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        int nextUnique = arr[0]+1;
        int ops = 0, len = arr.size();
        for(int i=1; i<len; i++)
        {
            // cout<<i<<" : "<<nextUnique<<" "<<arr[i]<<endl;
            nextUnique = max(nextUnique, arr[i]);
            ops += (nextUnique-arr[i]);
            nextUnique++;
        }
        return ops;
    }
};
