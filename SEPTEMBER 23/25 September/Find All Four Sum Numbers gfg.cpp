class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes 
        int n = arr.size();
        sort(arr.begin(), arr.end());
        set<vector<int>> fourSums;
        int l, r, target;
        for(int i=0; i<(n-3); i++)
        {
            for(int j=i+1; j<(n-2); j++)
            {
                l = j+1;
                r = n-1;
                target = k-arr[i]-arr[j];
                while(l<r)
                {
                    if(arr[l]+arr[r] > target)
                        r--;
                    else if(arr[l]+arr[r] < target)
                        l++;
                    else
                    {
                        fourSums.insert({arr[i], arr[j], arr[l], arr[r]});
                        r--;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it:fourSums)
            ans.push_back(it);
        return ans;
    }
};


