class Solution{
public:	
	
	int superPrimes(int n)
	{
	   // bool prime[n+1];
	   // memset(prime,true,n+1);
	   
	   vector<bool> prime(n+1,true);
	    
	    for(int i=2;i<=sqrt(n);i++){
	        if(prime[i]){
	            for(int j=i*i;j<=n;j+=i)
	                prime[j]=false;
	        }
	    }
	   // for(int i=2;i<=n;i++)
	   //     if(prime[i]) cout<<i<<" ";
	   // cout<<'\n';
	    int count=0;
	    count=0;
	    for(int i=3;i<=(n-2);i++){
	        if(prime[i]==true && prime[i+2]==true)
	            count++;
	    }
	       
	   return count;
	}
};
