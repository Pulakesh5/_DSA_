class Solution{
public:
    int findHeight(int N, int arr[]){
        return height(arr,N-1);
    }
    int height(int arr[], int n){
        if(arr[n]==-1) return 1;
        return 1 + height(arr,arr[n]);
    }
};
