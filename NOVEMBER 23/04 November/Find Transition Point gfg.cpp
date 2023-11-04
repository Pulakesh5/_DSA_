class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
        // code here
        int l=0,r=n-1,index;
        while(l<r)
        {
            index = (l+r)/2;
            if(arr[index]==1)
                r=index;
            else
                l = index+1;
        }
        if(l<n & arr[l]==1)
            return l;
        return -1;
    }
};
