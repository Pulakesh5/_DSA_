class Solution{
public:	
	bool exists(vector<vector<int>> &mat2, int key)
	{
	    int n = mat2.size();
	    int l = 0, h = n*n-1, index;
	    int r, c;
	    while(l<=h)
	    {
	        index = l+(h-l)/2;
	        r = index/n;
	        c = index%n;
	        if(mat2[r][c]==key)
	            return true;
	        else if(mat2[r][c]>key)
	            h = index-1;
	        else if(mat2[r][c]<key)
	            l = index+1;
	    }
	    return false;
	}
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    int k1=0,k2=0;
	    int r1, c1, r2, c2, num1=0, num2=0;
	    int size = n*n;
	    int sumCount=0;
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            if(exists(mat2, x-mat1[i][j]))
	            {
	               // cout<<i<<" "<<j<<" : "<<
	                sumCount++;
	            }
	        }
	    }
	    return sumCount;
	}
	
};
