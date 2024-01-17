class Solution {
  public:
    set<vector<int>> allPerms;
    void permute(vector<int> arr, int index)
    {
        int n = arr.size();
        // cout<<"calling with "<<index<<endl;

        if(index==n)
        {
            // for(int i=0; i<n; i++)
            //     cout<<arr[i]<<" ";
            // cout<<endl;
            allPerms.insert(arr);
            return;
        }
        for(int i=index; i<n; i++)
        {
            if(arr[index]==arr[i])
            {
                permute(arr, index+1);
            }
            else
            {
                swap(arr[index], arr[i]);
                permute(arr, index+1);
                swap(arr[index], arr[i]);
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        permute(arr,0);
        vector<vector<int>> ans(allPerms.begin(), allPerms.end());
        return ans;
    }
};
