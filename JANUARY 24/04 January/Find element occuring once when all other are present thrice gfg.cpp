class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // code here
        int bitCount=0, ans=0;
        for(int b=0; b<32; b++)
        {
            bitCount=0;
            for(int i=0; i<N; i++)
            {
                if(((arr[i]>>b)&1)==1)
                    bitCount++;
            }
            if(bitCount%3)
                ans+=(1<<b);
        }
        return ans;
        
    }
};
