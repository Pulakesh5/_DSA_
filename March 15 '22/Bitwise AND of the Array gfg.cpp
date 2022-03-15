class Solution{
    public:
    int count(int N, vector<int> A,int X)
    {
        int bitX=0;
        int ans=N;
        for(int i=31;i>=0;i--){
            if(X&(1<<i)){
                bitX|=(1<<i);
            }
            else{
                int temp = bitX + (1<<i),modify=0;
                for(auto num:A){
                    if( (temp&num)!=temp)
                        modify++;
                }
                ans=min(ans,modify);
            }
        }
        return ans;
    }
};
