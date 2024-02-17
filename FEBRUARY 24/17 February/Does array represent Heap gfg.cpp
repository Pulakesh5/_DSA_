class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        bool isHeap=true;
        for(int i=1; i<=n && isHeap; i++)
        {
            int lchild=2*i;
            int rchild=2*i+1;
            if(lchild<=n && arr[i-1]<arr[lchild-1])
                isHeap=false;
            // cout<<i<<" "<<isHeap<<endl;
            if(rchild<=n && arr[i-1]<arr[rchild-1])
                isHeap=false;
            // cout<<i<<" "<<isHeap<<endl;
        }
        return isHeap;
    }
};
