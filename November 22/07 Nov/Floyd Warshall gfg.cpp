	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int V=matrix.size();
	    
	    //vector<vector<int>> distance(V,vector<int>(V));
	    
	    for(int k=0;k<V;k++)
	    {
	        for(int i=0;i<V;i++)
	        {
	            //if( ) continue;
	            //if(matrix[i][j]==-1) matrix[i][j]=INF;
	            for(int j=0;j<V;j++)
	            {
	                //matrix[i][k]!=-1 && matrix[k][j]!=-1 &&
	                if(i==j || k==j || i==k || (matrix[i][k]==-1 | matrix[k][j]==-1)) continue;
	                
	                
	                if(matrix[i][j]==-1) matrix[i][j]=matrix[i][k]+matrix[k][j];
	                else if(matrix[i][k]+matrix[k][j] < matrix[i][j])
	                    matrix[i][j]=matrix[i][k]+matrix[k][j];
	            }
	        }
	    }
	}
