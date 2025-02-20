class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        
        priority_queue<int> mx;
        priority_queue<int, vector<int>, greater<int>> mn;
        int N = arr.size();
        vector<double> result(N);
        for(int i=0; i<N; i++)
        {
            if(mx.empty() || arr[i]<=mx.top())
                mx.push(arr[i]);
            else
                mn.push(arr[i]);
            
            if(mx.size() > mn.size()+1)
            {
                mn.push(mx.top());
                mx.pop();
            }
            
            if(mn.size() > mx.size())
            {
                mx.push(mn.top());
                mn.pop();
            }
            
            if(mx.size() == mn.size())
                result[i] = (mn.top() + mx.top())/2.0;
            else
                result[i] = 1.0*mx.top();
        }
        return result;
    }
};
