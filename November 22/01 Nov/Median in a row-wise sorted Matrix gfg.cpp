    int median(vector<vector<int>> &matrix, int R, int C){
        // code here  
        int mn=INT_MAX,mx=INT_MIN;
        
        for(int i=0;i<R;i++)
        {
            if(matrix[i][0]<mn)
                mn=matrix[i][0];
            if(matrix[i][C-1]>mx)
                mx=matrix[i][C-1];
        }
        
        int mid,midPos,med=(R*C+1)/2;
        
        while(mn<mx)
        {
            midPos=0;
            mid=(mn+mx)>>1;
            for(int i=0;i<R;i++)
                midPos+=(upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());
                
            if(midPos<med)
                mn=mid+1;
            else
                mx=mid;
        }
        
        return mn;

    }
