class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        
        // Your code here
        if(n==1)
            return;
        else if(n==2)
        {
            swap(arr[0], arr[1]);
            return;
        }
        else
        {
            for(int i=1; i<n; i+=2)
                swap(arr[i], arr[i-1]);
            return;
        }
        
    }
};
