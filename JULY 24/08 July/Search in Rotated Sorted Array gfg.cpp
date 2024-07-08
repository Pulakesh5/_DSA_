class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int N = arr.size();
        for(int i=0; i<N; i++){
            if(arr[i] == key){
                return i;
            }
        }
        return -1;
    }
};
