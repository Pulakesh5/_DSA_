class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n));
        int row=0,col=0;
        int not_vis=n*n;
        int cur=1;
        while(not_vis){
            int temp_row=row,temp_col=col; // horizontal left->right
            //cout<<"hr "<<temp_row<<" "<<temp_col<<'\n';
            for(int hr=temp_col;hr<(n-col) && not_vis;hr++){
                mat[temp_row][hr]=cur++;
                not_vis--;
                temp_col=hr;
            }
            temp_row++;
            //cout<<"vd "<<temp_row<<" "<<temp_col<<'\n';
            for(int vd=temp_row;vd<(n-row) && not_vis;vd++)
            {
                mat[vd][temp_col]=cur++;
                not_vis--;
                temp_row=vd;
            }
            //temp_col++;
            temp_col--;
            //cout<<"hl "<<temp_row<<" "<<temp_col<<'\n';
            for(int hl=(temp_col);hl>=col && not_vis;hl--){
                mat[temp_row][hl]=cur++;
                not_vis--;
                temp_col=hl;
            }
            temp_row--;
            //cout<<"vu "<<temp_row<<" "<<temp_col<<'\n';
            for(int vu=temp_row; vu>col && not_vis;vu--){
                mat[vu][temp_col]=cur++;
                not_vis--;
            }
            row++;col++;
        }
        return mat;
        
    }
};
