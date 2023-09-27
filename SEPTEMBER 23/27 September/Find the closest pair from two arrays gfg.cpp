class Solution{
  public:

    vector<int> printClosest(int arr[], int brr[], int n, int m, int target) {
        //code here
        int distance = INT_MAX, closeness, lb;
        vector<int> closePair;
        int i=0, j=m-1;
        while(i<n && j>-1)
        {
            closeness = abs(arr[i]+brr[j] - target);
            if(closeness < distance)
            {
                // cout<<closeness<<" "<<arr[i]<<" "<<brr[j]<<endl;
                closePair = {arr[i], brr[j]};
                distance = closeness;
            }
            else if( (arr[i]+brr[j]) < target)
                i++;
            else if(arr[i]+brr[j] > target)
                j--;
            else
                break;
        }
        return closePair;
    }
};
