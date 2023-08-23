long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
        sort(arr, arr+n);
        // for(int i=0; i<n; i++)
        //     cout<<arr[i]<<" ";
        // cout<<endl;
        
        long long count = 0, target, ub, tempSum;
        long long i2, i3;
        
        for(int i1=0; i1<(n-2); i1++)
        {
            i2 = i1+1;
            i3 = n-1;
            while(i2<i3)
            {
                // cout<<i1<<" ,"<<i2<<" ,"<<i3<<" : "<<count<<endl;
                tempSum = (arr[i1] + arr[i2] + arr[i3]);
                if(tempSum<sum)
                {
                    count+=(i3-i2);
                    i2++;
                }
                else
                    i3--;
                // cout<<i1<<" ,"<<i2<<" ,"<<i3<<" "<<tempSum<<" : "<<count<<endl;
            }
        }
        
        return count;
	}
