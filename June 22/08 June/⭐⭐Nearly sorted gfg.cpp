class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        vector<int> ans;
        priority_queue<int> pq;
        for(int i=0;i<=k;i++)
            pq.push(-1*arr[i]);
        
        for(int i=k+1;i<n;i++){
            ans.push_back(-1*(pq.top()));
            pq.pop();
            pq.push(-1*arr[i]);
        }
        while(!pq.empty()){
            ans.push_back(-1*(pq.top()));
            pq.pop();
        }
        
        return ans;
    }
};
