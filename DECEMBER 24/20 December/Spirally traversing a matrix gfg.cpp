class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int r = matrix.size(), c = matrix[0].size();
        vector <int> arr;
        int k=0, total=r*c;
        int row_strt=0,row_end=r-1,col_strt=0,col_end=c-1;
        
        while(col_strt<=col_end && row_strt<=row_end)
        {  
            // cout<<"printing rowstrt="<<row_strt<<'\n';
            for(int j=col_strt; j<=col_end && k<total; j++, k++)
                arr.push_back(matrix[row_strt][j]);
            row_strt++;
            
            // cout<<"printing colend="<<col_end<<'\n';
            for(int i=row_strt; i<=row_end && k<total; i++, k++)
                arr.push_back(matrix[i][col_end]);
            col_end--;
            
            // cout<<"printing rowend="<<row_end<<'\n';
            for(int j=col_end;j>=col_strt && k<total;j--, k++)
                arr.push_back(matrix[row_end][j]);
            row_end--;
            
            // cout<<"printing colstrt="<<col_strt<<'\n';
            for(int i=row_end;i>=row_strt && k<total; i--, k++)
                arr.push_back(matrix[i][col_strt]);
            col_strt++;
            
            // cout<<"\n";
        }
        return arr;
    }
};
