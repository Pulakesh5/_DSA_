class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int i=0, j=n-1;
            while(i<m && j>=0 && arr1[j]>=arr2[i])
            {
                swap(arr1[j], arr2[i]);
                i++;
                j--;
            }
            sort(arr1, arr1+n);
            sort(arr2, arr2+m);
        } 
};
