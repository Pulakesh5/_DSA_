	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> pos,neg;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0) pos.push_back(arr[i]);
	        else neg.push_back(arr[i]);
	    }
	    int pp=pos.size(), np=neg.size(), i=0, k=0;
	    for(i=0;i<min(pp,np);i++){
	        arr[k++]=pos[i];
	        arr[k++]=neg[i];
	    }
	    //cout<<pp<<" "<<np<<" "<<i<<" "<<k<<endl;
	    while(i<pp){
	        arr[k++]=pos[i++];
	    }
	    while(i<np){
	        arr[k++]=neg[i++];
	    }
	    
	}
