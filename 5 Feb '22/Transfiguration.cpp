#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
/*
  start traversing from the end, while they match keep decreasing both
  when they mismatch stop changing j this way j won't be changed for that substring which has been misplaced 
  due to those operations
  ans would be j
*/
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	int n1=A.length(),n2=B.length();
    	int count1[125],count2[125];
    	
    	memset(count1,0,sizeof(count1));
    	memset(count2,0,sizeof(count2));
    	if(n1!=n2)
    	return -1;
    	for(int i=0;i<n1;i++){
    	    count1[A[i]-'A']++;
    	    count2[B[i]-'A']++;

    	}
    	
    	for(int i=0;i<125;i++){
    	    if(count1[i]!=count2[i])
    	        return -1;
    	}
    	
    	reverse(A.begin(), A.end());
    	reverse(B.begin(), B.end());
    	
    	int j=0;
    	
    	for(int i=0;i<n1;i++){
    	    if(A[i]==B[j])
    	        j++;
    	    if(j==n2)
    	        break;
    	}
    	return n2-j;
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends
