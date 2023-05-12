    int arrayOperations(int n, vector<int> &arr) {
        // code here
        bool flag = false, zero = false;
        int subArray = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                flag = true;
                continue;
            }
            subArray+=flag;
            zero = true;
            flag = false;
        }
        subArray+=flag;
        if(!zero) return -1;//
        return subArray;
    }
