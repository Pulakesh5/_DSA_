class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        vector<int> closest;
        int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = lb-1, right = lb;
        if(lb<n && arr[lb]==x)
            right = lb+1;
        
        int lDiff, rDiff;
        while(k && left>=0 && right<n)
        {
            lDiff = x - arr[left];
            rDiff = arr[right] - x;
            if(lDiff<rDiff)
            {
                closest.push_back(arr[left]);
                left--;
            }
            else
            {
                closest.push_back(arr[right]);
                right++;
            }
            k--;
        }
        while(k && left>=0)
        {
            closest.push_back(arr[left]);
            left--;
            k--;
        }
        while(k && right<n)
        {
            closest.push_back(arr[right]);
            right++;
            k--;
        }
        return closest;
    }
};
