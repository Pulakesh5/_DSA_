class Solution {
  public:
    bool sign(int x)
    {
        return x<0;
    }
    vector<int> makeBeautiful(vector<int> arr) {
        int n=arr.size();
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(ans.empty())
            {
                ans.push_back(arr[i]);
                continue;
            }
            else if(sign(ans.back())!=sign(arr[i]))
                ans.pop_back();
            else
                ans.push_back(arr[i]);
        }
        return ans;
    }
    
};
