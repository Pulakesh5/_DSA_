class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        sort(arr, arr+n);
        int i = 0, same, count;
        vector<int> freq(1e5+5,0);
        while(i<n)
        {
            same = arr[i];
            count = 1;
            i++;
            while(i<n && arr[i] == same)
            {
                count++;
                i++;
            }
            freq[count]++;
        }
        
        for(int count=1; count<=n; count++)
        {
            if(freq[count]>1)
                return false;
        }
        return true;
    }
};
