class Solution {
  public:
    int isPossible(int N, int arr[]) {
        // code here
        int mod=0;
        
        while(N--)
            mod = (mod+arr[N]%3)%3;
        return mod==0;
    }
};
