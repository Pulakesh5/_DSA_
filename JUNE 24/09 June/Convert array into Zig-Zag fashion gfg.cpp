class Solution {
  public:
    void zigZag(int n, vector<int> &arr) {
        int len = arr.size();
        if(len==1)
            return;

        if(arr[0]>arr[1])
            swap(arr[0], arr[1]);
        for(int i=1; i+1<len; i+=2)
        {

            if(arr[i+1]>arr[i])
                swap(arr[i], arr[i+1]);
            if(arr[i-1]>arr[i])
                swap(arr[i-1], arr[i]);
            
            // if(!(arr[i-1]<arr[i] && arr[i]>arr[i+1]))
                // cout<<i<<" : "<<arr[i-1]<<" "<<arr[i]<<" "<<arr[i+1]<<endl;
        }
        if(len%2==0 && arr[len-1]<arr[len-2])
            swap(arr[len-1], arr[len-2]);
    }
};
