class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code 
        vector<int> celebs;
        int N = mat.size();
        for(int i=0; i<N; i++)
        {
            int count=0;
            for(int j=0; j<N; j++)
                count+=mat[i][j];
            if(count==0)
                celebs.push_back(i);
        }
        if(celebs.size()==0 || celebs.size()>1)
            return -1;
        
        for(int i=0; i<N; i++)
        {
            if(i==celebs[0])    
                continue;
            else if(mat[i][celebs[0]]==0)
                return -1;
        }
        return celebs[0];
    }
};
