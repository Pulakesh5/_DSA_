class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        // Code here
        int N = arr.size();
        vector<int> ans(N, -1);
        int pos = 0;
        while(pos<N) {
            if(arr[pos]>=0 && arr[pos]<N)
                ans[arr[pos]] = arr[pos];
            pos++;
        }
        
        return ans;
    }
};
