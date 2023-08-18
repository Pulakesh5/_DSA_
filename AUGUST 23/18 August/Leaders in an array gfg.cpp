class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        // stack<int> monotonicIncStack;
        // monotonicIncStack.push(a[n-1]);
        int nextLeader = a[n-1];
        vector<int> leader;
        for(int i=n-1; i>=0; i--)
        {
            // while(!monotonicIncStack.empty() && monotonicIncStack.top()>)
            if(a[i]>=nextLeader)
            {
                nextLeader = a[i];
                leader.push_back(a[i]);
                // cout<<a[i]<<endl;
            }
        }
        reverse(leader.begin(), leader.end());
        return leader;
        
    }
};
