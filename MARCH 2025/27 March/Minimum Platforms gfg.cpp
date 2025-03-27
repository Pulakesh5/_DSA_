class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int tmp = 0;
        int i=0, j=0; 
        int platform = 1;
        while(i<n && j<n) {
            if(arr[i]<=dep[j])
            {
                i++;
                tmp++;
                platform = max(platform, tmp);
            }
            else {
                tmp--;
                j++;
            }
        }
        return platform;
    }
};
