class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<k; i++)
            pq.push({arr[i], i});
            
        int N = arr.size();
        vector<int> k_sub_max;
        k_sub_max.push_back(pq.top().first);
        // processing rest of n-k subarrays
        for(int i=k; i<N; i++)
        {
            pq.push({arr[i], i});
            while(i-pq.top().second>=k)
                pq.pop();
            k_sub_max.push_back(pq.top().first);
        }
        return k_sub_max;
        
    }
};
