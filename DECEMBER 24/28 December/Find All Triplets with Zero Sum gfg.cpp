class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        size_t N = arr.size();
        map<int, vector<int>> index;
        vector<vector<int>> triplets;

        for(int i=0; i<N; i++)
        {
            if(index.find(arr[i])==index.end())
                index[arr[i]] = {i};
            else
                index[arr[i]].push_back(i);
        }
        
        for(int i=0; i<(N-2); i++)
        {
            for(int j=i+1; j<(N-1); j++)
            {
                vector<int> Index = index[-1*(arr[i]+arr[j])];
                int lb = lower_bound(Index.begin(), Index.end(), j+1) - Index.begin();
                while(lb<Index.size())
                    triplets.push_back({i, j, Index[lb++]});
            }
        }
        
        return triplets;
    }
};
