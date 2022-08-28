class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size();
        int p,i,j;
        
        vector<int> temp;
        
        for(int k=0;k<c;k++){
            i=0;j=k;
            
            for( ;i<r && j<c; i++,j++){
                temp.push_back(mat[i][j]);
            }
            sort(temp.begin(), temp.end());
            p=0; i=0; j=k;
            
            for( ;i<r && j<c; i++,j++){
                mat[i][j]=temp[p++];
            }
            temp.clear();
            //clear(temp.begin(),temp.end());
        }
        
        for(int k=1;k<r;k++){
            i=k; j=0;
            
            for( ;i<r && j<c; i++,j++){
                temp.push_back(mat[i][j]);
            }
            sort(temp.begin(), temp.end());
            p=0; i=k; j=0;
            
            for( ;i<r && j<c; i++,j++){
                mat[i][j]=temp[p++];
            }
            temp.clear();
            //clear(temp.begin(),temp.end());
        }
        
        return mat;
    }
};
