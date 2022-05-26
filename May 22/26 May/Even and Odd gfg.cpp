class Solution {
  public:
    void reArrange(int arr[], int n) {
        int even=0,odd=1;
        while(even<n && odd<n){
            if(arr[even]%2==0 && arr[odd]%2==1){
                even+=2;
                odd+=2;
            }
            else if(arr[even]%2==1 && arr[odd]%2==0){
                swap(arr[even],arr[odd]);
                odd+=2;
                even+=2;
            }
            else if(arr[even]%2==1){
                odd+=2;
            }
            else
                even+=2;
        }
    }
};
