class Solution {
  public:
    int completeRows(int n) {
        // code here
        int row =0;
        int totalBrick = 0;
        while(1)
        {
            if(totalBrick>n)
                return row-1;
            row++;
            totalBrick+=row;
        }
        return -1;
    }
};
