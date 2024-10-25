class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        vector<int> aux(arr.begin(), arr.end());
        sort(aux.begin(), aux.end());
        int n = arr.size(), k = n-1;
        for(int i=0; i<n; i+=2)
            arr[i] = aux[k--];
        k = 0;
        for(int i=1; i<n; i+=2)
            arr[i] = aux[k++];
        return arr;
    }
};
