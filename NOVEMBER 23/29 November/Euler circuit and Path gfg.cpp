class Solution {
public:
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    int even=0, odd=0;
	    for(int i=0; i<V; i++)
	    {
	        (adj[i].size()%2 == 0) ? even++ : odd++;
	    }
	    if(even==V)
	        return 2;
	    else if(odd==2)
	        return 1;
	    else
	        return 0;
	}
};
