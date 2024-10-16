class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        int ch=2;
        for(int i=0, p=1; i<(arr.size()+1)/2; i++, p++){
            if(p!=arr[i] and ch){
                swap(arr[i], arr[arr[i]-1]); ch--;
            }
        }
        return (ch==2) or (ch==0 and is_sorted(arr.begin(), arr.end()));
    }
};
