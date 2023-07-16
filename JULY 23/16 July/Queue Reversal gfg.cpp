class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
        int qSize = q.size();
        vector<int> aux;
        
        for(int i=0; i<qSize; i++)
        {
            aux.push_back(q.front());
            q.pop();
        }
        for(int i=0; i<qSize; i++)
            q.push(aux[qSize-1-i]);
        return q;
    }
};
