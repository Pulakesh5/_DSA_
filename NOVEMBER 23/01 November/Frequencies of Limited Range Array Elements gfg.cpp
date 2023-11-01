class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        int MOD = 1e5;
        for(int i=0; i<N; i++)
        {
            if(arr[i]%MOD<=N)
                arr[arr[i]%MOD-1]+=MOD;
        }
        for(int i=N-1; i>-1; i--)
        {
            arr[i] = arr[i]/MOD;
        }
    }
};
