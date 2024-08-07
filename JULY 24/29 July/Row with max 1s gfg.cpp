class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int N = arr.size(), M = arr[0].size();
        int max1Row = -1, maxCount = 0, count=0;
        for(int i=0; i<N; i++)
        {
            count = 0;
            for(int j=0; j<M; j++)
            {
                if(arr[i][j])
                    count++;
            }
            if(count>maxCount)
            {
                maxCount = count;
                max1Row = i;
            }
        }
        return max1Row;
    }
};
