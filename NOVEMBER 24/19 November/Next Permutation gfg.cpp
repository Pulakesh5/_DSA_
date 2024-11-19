class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        // shortest solution:
        // next_permutation(arr.begin(), arr.end());
        size_t len = arr.size();
        if(len==1)
            return;
        
        int inflexionPoint = len-2;
        while(inflexionPoint>=0)
        {
            if(arr[inflexionPoint]<arr[inflexionPoint+1])
                break;
            inflexionPoint--;
        }
        if(inflexionPoint<0)
        {
            sort(arr.begin(), arr.end());
            return;
        }
        int p=inflexionPoint+1;
        int nextMax = p;
        while(p<len)
        {
            if(arr[p]>arr[inflexionPoint] && arr[nextMax]>arr[p])
                nextMax = p;
            else if(arr[p]<=arr[inflexionPoint])
                break;
            p++;
        }
        swap(arr[inflexionPoint], arr[nextMax]);
        sort(arr.begin()+inflexionPoint+1, arr.end());
    }
};
