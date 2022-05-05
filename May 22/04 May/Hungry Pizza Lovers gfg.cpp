vector<int> permute(vector<vector<int>> &arr, int n)
{
    
    priority_queue<pair<int,int>> pq;
    
    for(int i=0;i<n;i++){
        pq.push({arr[i][0]+arr[i][1],i+1});
    }
    vector<int> ans;
    while(!pq.empty()){
        auto pr=pq.top();
        ans.push_back(pr.second);
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    
    return ans;
}
