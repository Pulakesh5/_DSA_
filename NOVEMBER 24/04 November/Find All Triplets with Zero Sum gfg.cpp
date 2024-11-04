class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        size_t N = arr.size();
        
        map<int, vector<int>> index;
        
        for(int i=0; i<N; i++)
        {
            if(index.find(arr[i])==index.end())
                index[arr[i]] = {i};
            else 
                index[arr[i]].push_back(i);
        }
        
        vector<vector<int>> triplets;
        
        for(int i=0; i<N; i++)
        {
            for(int j=i+1; j<N; j++)
            {
                int target = -1*(arr[i]+arr[j]);
                if(index.find(target)!=index.end())
                {
                    vector<int> Index = index[target];
                    size_t IndexSize = Index.size();
                    int lb = lower_bound(Index.begin(), Index.end(), j+1) - Index.begin();
                    while(lb<IndexSize)
                        triplets.push_back({i, j, Index[lb++]});
                }
            }
        }
        return triplets;
    }
};
