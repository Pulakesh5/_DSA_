class Solution {
  public:
    int solve(vector<int> &arr, int l, int r)
    {
        
        int n = arr.size();
        if(r-l == 0)
            return arr[l];
        if(r-l == 1)
            return max(arr[l], arr[r]);
    
        int last = 0, secondLast = 0, tmp;
        for(int i=l; i<=r; i++)
        {
            tmp = max(last, secondLast+arr[i]);
            secondLast = last;
            last = tmp;
        }
        return last;
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        int option1 = solve(arr, 0, n-2);
        int option2 = solve(arr, 1, n-1);
        return max(option1, option2);
    }
};
