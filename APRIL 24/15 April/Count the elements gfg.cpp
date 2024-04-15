class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        vector<int> countElement(q);
        sort(b.begin(), b.end());
        for(int i=0; i<q; i++)
        {
            int count = upper_bound(b.begin(), b.end(), a[query[i]]) - b.begin();
            countElement[i] = count;
        }
        return countElement;
    }
};
