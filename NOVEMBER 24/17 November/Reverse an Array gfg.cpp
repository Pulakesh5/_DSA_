class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int l=0, r=arr.size()-1;
        while(l<r)
        {
            swap(arr[l++], arr[r--]);
        }
    }
};
