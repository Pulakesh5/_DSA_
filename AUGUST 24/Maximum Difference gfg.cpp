class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int N = arr.size();
        vector<int> leftSmaller(N);
        stack<int> stk;
        stk.push(arr[0]);
        for(int i=1; i<N; i++)
        {
            while(!stk.empty() && stk.top()>=arr[i])
                stk.pop();

            if(stk.empty())
                leftSmaller[i] = 0;
            else
                leftSmaller[i] = stk.top();
            stk.push(arr[i]);
        }
        while(stk.size())
            stk.pop();
        stk.push(arr[N-1]);
        int rightSmaller = arr[N-1];
        int maxDiff = leftSmaller[N-1];
        for(int i=N-2; i>=0; i--)
        {
            while(!stk.empty() && stk.top()>=arr[i])
                stk.pop();
            
            rightSmaller = (stk.empty()? 0 : stk.top());
            maxDiff = max(maxDiff, abs(rightSmaller-leftSmaller[i]));
            stk.push(arr[i]);
        }
        return maxDiff;
    }
};
