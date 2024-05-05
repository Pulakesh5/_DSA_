class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        int l=0, r=n-1;
        d = d%n;
        while(l<r)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
        l=0, r = n-1-d;
        while(l<r)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
        l = n-d, r=n-1;
        while(l<r)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
};
