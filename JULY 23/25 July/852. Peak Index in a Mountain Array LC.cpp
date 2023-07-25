class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int len = arr.size();
        vector<bool> front(len+1,false), reverse(len+1,false);
        front[0] = true;
        reverse[len-1] = true;
        for(int i=1; i<(len-1); i++)
        {
            front[i] = front[i-1]&(arr[i-1]<arr[i]);
            reverse[len-1-i] = reverse[len-i]&(arr[len-1-i]>arr[len-i]);
        }

        int low = 1, high = len-2, index;
        while(low<=high)
        {
            index = (low+high)/2;
            // cout<<index<<" "<<front[index]<<" "<<reverse[index]<<endl;
            if(front[index] & reverse[index])
                return index;
            else if(front[index] & !reverse[index])
                low = index + 1;
            else if(!front[index] & reverse[index])
                high = index - 1;
        }
        return -1;
    }
};
