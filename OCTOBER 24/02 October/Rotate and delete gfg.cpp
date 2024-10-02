class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        // Your code here
        int N = arr.size();
        for (int k=1; k<=(N/2); k++) {
            arr.insert(arr.begin(), arr.back());
            arr.pop_back();
            arr.erase(arr.end()-k);
        }
        return arr[0];
    }
};
