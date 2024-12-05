class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        vector<int> count(3,0);
        for(int num:arr)
            count[num]++;
        int index=0;
        for(int num=0; num<3; num++)
        {
            while(count[num]--)
                arr[index++] = num;
        }
    }
};
