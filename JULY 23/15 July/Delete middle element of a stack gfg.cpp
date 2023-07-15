class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        stack<int> aux;
        int i = 0;
        while(i++<(sizeOfStack/2))
        {
            aux.push(s.top());
            s.pop();
        }
        s.pop();
        while(!aux.empty())
        {
            s.push(aux.top());
            aux.pop();
        }
    }
};  
