class Solution {
public:
	int isPossible(vector<vector<int>>paths){
	    // Code here
	    int n = paths.size(),degree;
	    for(int i=0; i<n; i++)
	    {
	        degree = 0;
	        for(int j=0; j<n; j++)
	            degree+=paths[i][j];
	        if(degree&1)
	            return false;
	    }
	    return true;
	}

};
