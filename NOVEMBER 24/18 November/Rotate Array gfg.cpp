class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        size_t len = arr.size();
        d%=len;
        int l=0, r=len-1;
        while(l<r)
        {
            swap(arr[l++], arr[r--]);
        }
        l = 0;
        r = len-d-1;
        while(l<r)
        {
            swap(arr[l++], arr[r--]);
        }
        l = len-d;
        r = len-1;
        while(l<r)
        {
            swap(arr[l++], arr[r--]);
        }
    }
};
