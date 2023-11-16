class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        bool isSorted=true;
        int len = arr.size();

        for(int i=1; i<len && isSorted; i++)
        {
            if(arr[i]<arr[i-1])
                isSorted = false;
        }
        cout<<isSorted<<endl;
        if(!isSorted)
            sort(arr.begin(), arr.end());
        // for(int num:arr)
        //     cout<<num<<" ";
        // cout<<endl;
        int prev = 1;
        for(int i=1; i<len; i++)
        {
            cout<<arr[i]<<" "<<prev<<" : ";
            if(arr[i]-prev<=1)
                prev = arr[i];
            else
                prev++;
            cout<<prev<<endl;
        }
        return prev;
    }
};
