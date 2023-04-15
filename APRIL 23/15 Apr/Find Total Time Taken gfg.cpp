    int totalTime(int n, vector<int> &arr, vector<int> &time) {
        // code here
        long long totalTime=0;
        set<int> st;
        for(int i=0;i<n;i++)
        {
            // cout<<i<<" "<<arr[i]<<" , "<<totalTime<<" ";
            if(st.find(arr[i])==st.end() && i!=0)
                totalTime++;
            else if(st.find(arr[i])!=st.end())
            {
                // cout<<"time "<<time[arr[i]-1]<<" ";
                totalTime+=time[arr[i]-1];
            }
            st.insert(arr[i]);
            // cout<<totalTime<<endl;
        }
        return totalTime;
    }
