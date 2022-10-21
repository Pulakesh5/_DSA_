    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        int rs=0,re=R-1,cs=0,ce=C-1,i,j;
        int t=R*C;
        vector<int> v;
        while(t)
        {
            i=rs;j=cs;
            while(j<=ce && t>0){
                v.push_back(a[i][j++]);
                t--;
            } 
            rs++;
            i=rs;j=ce;
            
            while(i<=re && t>0){
                v.push_back(a[i++][j]);
                t--;
            }  
            ce--;
            i=re;j=ce;
            
            while(j>=cs && t>0){
                v.push_back(a[i][j--]);
                t--;
            }
                
            re--;
            j=cs;i=re;
            while(i>=rs && t>0)
            {
                v.push_back(a[i--][j]);
                t--;
            }
            cs++;
        }
        reverse(v.begin(),v.end());
        return v;
    }
