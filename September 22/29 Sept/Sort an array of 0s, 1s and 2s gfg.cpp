void sort012(int a[], int n)
    {
        // code here 
        int count0=0,count1=0,count2=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)  count0++;
            else if(a[i]==1) count1++;
            else count2++;
        }
        int k=0;
        for(int i=0;i<count0;i++) a[k++]=0;
        for(int i=0;i<count1;i++) a[k++]=1;
        for(int i=0;i<count2;i++) a[k++]=2;
    }
