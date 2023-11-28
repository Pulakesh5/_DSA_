class Solution {
  public:
    int sumOfDependencies(vector<int> adj[], int V) {
        // code here
        int depSum = 0;
        for(int i=0; i<V; i++)
            depSum+=adj[i].size();
        return depSum;
    }
};
