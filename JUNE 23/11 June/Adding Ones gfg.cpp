class Solution{
    public:
    void update(int arr[], int n, int updates[], int k)
    {
        // Your code goes here
        sort(updates, updates + k);
        int prev = 0, j = 0;
        for(int i=0; i<n; i++)
        {
            while( j<k && i>=(updates[j]-1))
            {
                prev+=(i==(updates[j]-1));
                j++;
                
            }
            arr[i] = prev;
        }
        
    }
};
