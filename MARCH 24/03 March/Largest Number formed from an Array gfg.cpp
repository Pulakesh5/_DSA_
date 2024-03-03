static bool comp(string &a, string &b)
{
    return (a+b)>(b+a);
}
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(int n, vector<string> &arr) {
	    // code here
	    sort(arr.begin(),arr.end(),comp);
	    string largestNum = "";
	    for(int i=0; i<n; i++)
	        largestNum += arr[i];
	    return largestNum;
	}
};

