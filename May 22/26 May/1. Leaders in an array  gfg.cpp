class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int arr[], int n){
        int leader=arr[n-1];
        vector<int> _leader;
        _leader.push_back(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=leader){
                _leader.push_back(arr[i]);
                leader=arr[i];
            }
        }
        reverse(begin(_leader),end(_leader));
        return _leader;
        
    }
};
