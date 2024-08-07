class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<arr1.size(); i++)
            pq.push(arr1[i]);
        
        for(int i=0; i<arr2.size(); i++)
            pq.push(arr2[i]);
        
        for(int i=1; i<k; i++)
        {
            pq.pop();
        }
        return pq.top();
    }
};
