class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int j = 0;
        int n = arr.size();
        for (int i =0;i<n;i++){
            if(arr[i]!=0){
                int c = arr[j];
                arr[j] = arr[i];
                arr[i] = c;
                j++;
            }
        }
    }
};
