  public:
   int ans(vector<int> arr, int index, int k)
    {
         if(arr.size()==1)
            return arr[0];
        index=(index+k)%(arr.size());
        arr.erase(arr.begin()+index);
        return ans(arr,index,k);
    }
    int safePos(int n, int k) {
        // code here
        vector<int> arr;
        int index=0;
        k--;
        for(int i=1;i<=n;i++)
        {
            arr.push_back(i);
        }
        return ans(arr,index,k);
    }
   
};
