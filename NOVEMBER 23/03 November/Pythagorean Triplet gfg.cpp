class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    unordered_set<int> squares;
	    for(int i=0; i<n; i++)
	        squares.insert(arr[i]*arr[i]);
	    
	    for(auto l=squares.begin(); l!=squares.end(); l++)
	    {
	        for(auto r=next(l); r!=squares.end(); r++)
	            if(squares.find((*l)+(*r)) != squares.end())
	                return true;
	    }
	    return false;
	}
};
