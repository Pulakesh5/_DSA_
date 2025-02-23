class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<int> stk;
        int n = arr.size();
        vector<int> nextGreater(n);
        nextGreater[n-1] = -1;
        stk.push(arr[n-1]);
        for(int i=n-2; i>-1; i--)
        {
            while(!stk.empty() && stk.top()<=arr[i])
                stk.pop();
            if(stk.empty())
                nextGreater[i] = -1;
            else
                nextGreater[i] = stk.top();
            stk.push(arr[i]);
        }
        return nextGreater;
    }
};
