class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int count0 = 0;
        for(int el:arr)
        {
            count0 += (el==0);
        }
        int  count1 = arr.size()-count0;
        int pos=0;
        while(count0--)
            arr[pos++] = 0;
        while(count1--)
            arr[pos++] = 1;
    }
};
