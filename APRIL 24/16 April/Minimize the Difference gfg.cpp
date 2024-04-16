class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {

        vector<int> post_max(n);
        vector<int> post_min(n);
        
        post_min[n-1] = arr[n-1];
        post_max[n-1] = arr[n-1];
        
        for(int i = n-2; i>= 0; --i) {
            post_max[i] = max(arr[i] , post_max[i+1]);
            post_min[i] = min(arr[i] , post_min[i +1]);
        }
        
        int min_diff = post_max[k] - post_min[k];
        int p_min = arr[0];
        int p_max = arr[0];
        
        
        for( int i = 1; i<n-k; ++i) {
            int curr_min = max(p_max , post_max[i+k]) - min(p_min , post_min[i+k]);
            min_diff = min( min_diff , curr_min);
            p_max = max(arr[i] , p_max);
            p_min = min(arr[i] , p_min);
        }
        
        min_diff = min( min_diff , p_max - p_min);
        
        return min_diff;
    }
};
