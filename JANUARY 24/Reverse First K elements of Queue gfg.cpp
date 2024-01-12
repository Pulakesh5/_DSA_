class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> stk;
        queue<int> ans;
        while(k--)
        {
            stk.push(q.front());
            q.pop();
        }
        while(!stk.empty())
        {
            ans.push(stk.top());
            stk.pop();
        }
        while(q.size())
        {
            ans.push(q.front());
            q.pop();
        }
        return ans;
    }
};
