class Solution {
public:
    int findPrimes(long long a)
    {
        long i=2, temp=0;
        while(i*i <= a && a>1)
        {
            if(a%i==0)
            {
                a=a/i;
                temp++;
            }
            if(a%i!=0)
                i++;
        }
        if(a!=1)
            temp++;
        return temp;
    }
	int sumOfPowers(int a, int b){
	    // Code here
	    int points=0, count;
	    
	    
	    for(int ticket=a; ticket<=b; ticket++)
	    {
	        int t=ticket;
            points += findPrimes(ticket);
	       // cout<<endl;
	    }
	    
	    return points;
	}
};
