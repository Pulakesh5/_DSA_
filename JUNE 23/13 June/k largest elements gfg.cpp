class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int, vector<int>, greater<int>> pq;
	    for(int i=0; i<n; i++)
	    {
	        pq.push(arr[i]);
	        if(i<k)
	            continue;
	        if(pq.size()>k)
	            pq.pop();
	    }
	    if(pq.size()==0)
	        return {};
	    int pqSize = pq.size();
	    vector<int> kLargest(pqSize);
	    for(int i=pqSize-1; i>=0; i--)
	    {
	        kLargest[i] = pq.top();
	        pq.pop();
	    }
	    return kLargest;
	}

};
