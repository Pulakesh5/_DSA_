class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here 
        vector<int> positive, negative;
        for(int num:arr)
        {
            if(num < 0)
                negative.push_back(num);
            else
                positive.push_back(num);
        }
        int lenPos = positive.size(), lenNeg = negative.size();
        int pPos = 0, pNeg = 0, index = 0;
        while(pPos<lenPos && pNeg<lenNeg)
        {
            // cout<<positive[pPos]<<" "<<negative[pNeg]<<endl;
            arr[index++] = positive[pPos++];
            arr[index++] = negative[pNeg++];
        }
        while(pPos<lenPos)
            arr[index++] = positive[pPos++];
        while(pNeg<lenNeg)
            arr[index++] = negative[pNeg++];
    }
};
