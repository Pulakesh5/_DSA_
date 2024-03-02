class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        map<int,int> frequency;
        for(int i=0; i<n; i++)
        {
            if(frequency[a[i]]==(k-1))
                return a[i];
            frequency[a[i]]++;
        }
        return -1;
    }
};
