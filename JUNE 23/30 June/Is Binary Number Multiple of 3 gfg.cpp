class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int len = s.size();
	    int setBits = 0;
	    
	    for(int i=len-1; i>=0; i-=2)
	        setBits+=(s[i]=='1');
	    
	    for(int i=len-2; i>=0; i-=2)
	        setBits-=(s[i]=='1');
	    
	    return abs(setBits)%3==0;
	}

};
