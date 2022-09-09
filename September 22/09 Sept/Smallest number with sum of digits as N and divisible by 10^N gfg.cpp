class Solution{
	public:
	string digitsNum(int N)
	{
	    // Code here.
	    int num=N,digit;
	    string number="";
	    while(num)
	    {
	        digit=min(9,num);
	        num-=digit;
	        number=to_string(digit)+number;
	    }
	    num=N;
	    while(num--)
	        number+='0';
	   return number;
	}
};
