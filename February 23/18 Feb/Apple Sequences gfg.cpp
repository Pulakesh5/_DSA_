int appleSequences(int n, int m, string arr){
        // code here 
        int i=0,j=0;
        queue<int> q;
        int ans=0, count;
        for(int i=0;i<n;i++)
        {
            if(arr[i]=='O')
                count++;
            while(j<n && count>m)
            {
                if(arr[j]=='O')
                    count--;
                j++;
            }
            ans = max(i-j+1, ans);
        }
        return ans;
    }
