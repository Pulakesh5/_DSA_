class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
        if(k==1)
            return arr;
        
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<(k-1); i++)
            pq.push({arr[i], i});
        int N = arr.size();
        vector<int> maxOfSubarrays;
        for(int i=k-1; i<N; i++)
        {
            pq.push({arr[i], i});
            while(pq.top().second<(i-k+1))
                pq.pop();
            maxOfSubarrays.push_back(pq.top().first);
        }
        return maxOfSubarrays;
    }
};
