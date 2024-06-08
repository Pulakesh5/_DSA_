class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        int p1=0, p2=0;
        n--;
        while(p1<n && arr1[p1]==arr2[p2])
        {
            p1++;
            p2++;
        }
        return p1;
    }
};
