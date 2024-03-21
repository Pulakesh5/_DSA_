vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	queue<Node*> q;
    	q.push(root);
    	int order = 0;
    	Node* node;
    	vector<int> traversal;
    	while(!q.empty())
    	{
    	    int qsize = q.size();
    	    vector<int>  aux;
    	    for(int i=0; i<qsize; i++)
    	    {
    	        node = q.front();
    	        q.pop();
    	        aux.push_back(node->data);
    	        
	            if(node->left)
	                q.push(node->left);
	            if(node->right)
	                q.push(node->right);
    	        
    	    }
    	    if(order==0)
    	    {
    	        for(int i=0; i<aux.size(); i++)
    	            traversal.push_back(aux[i]);
    	    }
    	    else
    	    {
    	        for(int i=aux.size()-1; i>=0; i--)
    	            traversal.push_back(aux[i]);
    	    }
    	    
    	    order = 1-order;
    	}
    	return traversal;
    }
