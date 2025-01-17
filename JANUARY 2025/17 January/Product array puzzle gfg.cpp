class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int len = arr.size();
        vector<int> product(len);
        int zeroCount = 0, index = -1;
        long long allProduct = 1ll;
        
        for(int i=0; i<len; i++)
        {
            if(arr[i]==0)
            {
                zeroCount += 1;
                index = i;
            }
            else
                allProduct *= arr[i];
        }
        
        if(zeroCount == 1)
            product[index] = allProduct;
        
        if(zeroCount>=1)
            return product;
            
        for(int i=0; i<len; i++)
            product[i] = (allProduct/arr[i]);
        return product;
    }
};
