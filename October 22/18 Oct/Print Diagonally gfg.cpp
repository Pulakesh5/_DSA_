	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int> diagonal;
		int row=A.size(),col=A[0].size();
		int r=0,c=0;
		int i,j;
		while(c<col)
		{
		    i=0;
		    j=c;
		    while(i<row && j>=0)
		    {
		        diagonal.push_back(A[i][j]);
		        i++;j--;
		    }
		    c++;
		}
		r=1;
		while(r<row)
		{
		    i=r;
		    j=col-1;
		    while(i<row && j>=0)
		    {
		        diagonal.push_back(A[i][j]);
		        i++;j--;
		    }
		    r++;
		}
		return diagonal;
	}
