This solution didn't work. Gave TLE, not sure why. The time complexity seems to be fine, a similar solution [commneted above] passed though. 
Will to figure out the issue 

class Solution {
//      int idx[4]={1,-1,0,0};
//     int idy[4]={0,0,1,-1};
//     bool helper(vector<vector<char>>& mat, string& word,int r,int c)
//     {
//          int row=mat.size(),col=mat[0].size();
        
//         if(word.size()==0)return true;
        
//         if(r<0||r>=row||c<0||c>=col||mat[r][c]!=word[0])return false;
        
        
//         string s=word.substr(1);
//         for(int i=0;i<4;i++)
//         {
            
//             int new_row=r+idx[i];
//             int new_col=c+idy[i];
            
//             char temp=mat[r][c];
//             mat[r][c]='.';
            
//             if(helper(mat,s,new_row,new_col))return true;
            
//             mat[r][c]=temp;
//         }
//         return false;
//     }
    
    
//   public:
//     bool isWordExist(vector<vector<char>>& mat, string& word) {
//         // Code here
        
//         int row=mat.size(),col=mat[0].size();
        
//         for(int i=0;i<row;i++)
//         {
//             for(int j=0;j<col;j++)
            
//             {    if(mat[i][j]!=word[0])continue;
//                 if(helper(mat,word,i,j))return true;
//             }
//         }return false;
//     }
    
    
  public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    // int ROW, COL, LEN;
    
    bool backtrack(vector<vector<char>> &mat, int x, int y, string &word)
    {
        if(word.size() == 0)
            return true;
        int ROW = mat.size(), COL = mat[0].size();
        if(!(x>=0 && y>=0 && x<ROW && y<COL && word[index] == mat[x][y]))
            return false;
        
        // cout<<"Called "<<x<<" "<<y<<" for i : "<<index<<" "<<word[index]<<endl;
        // visited[x][y] = true;
        
        for(int k=0; k<4; k++)    
        {
            char temp = word[index];
            word[index] = '.';
            if(backtrack(mat, x+dx[k], y+dy[k], word.substr(1)))
            {
                // cout<<"Returing 'true' "<<x<<" "<<y<<" for i : "<<index<<" "<<word[index]<<endl;
                return true;
            }
            word[index] = temp;
        }
        
        // visited[x][y] = false;
        // cout<<"Returing 'false' "<<x<<" "<<y<<" for i : "<<index<<" "<<word[index]<<endl;
        return false;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int ROW = mat.size(), COL = mat[0].size(), LEN = word.size();
        
        for(int i=0; i<ROW; i++)
        {
            for(int j=0; j<COL; j++)
            {
                if(word[0]!=mat[i][j])
                    continue;
                if(backtrack(mat, i, j, word, 0))
                    return true;
            }
        }
        
        return false;
    }
};
