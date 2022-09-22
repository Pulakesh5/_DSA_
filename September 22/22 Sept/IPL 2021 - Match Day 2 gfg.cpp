    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> res;
        unordered_map<int, int> umap;
        priority_queue<int> pq;
        
        for (int i = 0; i < k; i++) {
            umap[arr[i]]++;
            pq.push(arr[i]);
        }
        
        res.push_back(pq.top());
        
        for (int i = k; i < n; i++) {
            umap[arr[i]]++;
            umap[arr[i - k]]--;
            pq.push(arr[i]);
            
            while (!umap[pq.top()]) {
                pq.pop();
            }
            res.push_back(pq.top());
        }
        
        return res;
    }
