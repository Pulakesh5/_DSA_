    string ReFormatString(string S, int K){
    	vector<char> chars;
    	int n=S.length(),j=0;
    	string Key="";
    	reverse(S.begin(),S.end());
    	for(int i=0;i<n;i++)
    	{
    	    if(S[i]!='-')
    	    {
    	        if(j==K)
    	        {
    	            Key+='-';
    	            j=0;
    	        }
    	        Key+=((char)toupper(S[i]));
    	        j++;
    	        
    	    }
    	}
    	reverse(Key.begin(),Key.end());

    	return Key;
    }
