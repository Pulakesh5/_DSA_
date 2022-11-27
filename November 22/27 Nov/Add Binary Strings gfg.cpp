class Solution{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	    int na=A.size(), nb=B.size();
	    string ans="";
	    int sum=0,carry=0;
	    int i,j;
	    for(i=na-1,j=nb-1;i>=0 && j>=0;i--,j--)
	    {
	        sum=0;
	        sum+=(carry+A[i]-'0'+B[j]-'0');
	        //cout<<i<<" "<<j<<" sum = "<<sum<<", carry = "<<carry<<endl;
	        carry=sum>>1;
	        sum&=1;
	        ans.push_back(sum+'0');
	    }
	    while(i>=0)
	    {
	        sum=0;
	        sum+=(carry+A[i--]-'0');
	        //cout<<i<<" "<<j<<" sum = "<<sum<<", carry = "<<carry<<endl;
	        carry=sum/2;
	        sum&=1;
	        ans.push_back(sum+'0');
	    }
	    
	    while(j>=0)
	    {
	        sum=0;
	        sum+=(carry+B[j--]-'0');
	        //cout<<i<<" "<<j<<" sum = "<<sum<<", carry = "<<carry<<endl;
	        carry=sum/2;
	        sum&=1;
	        ans.push_back(sum+'0');
	    }
	    
	    if(carry>0) ans.push_back('1');
	    
	    while(ans.back()=='0') ans.pop_back();
	    
	    reverse(ans.begin(), ans.end());
	    
	    return ans;
	   // i=0;
	   // na=ans.size();
	    
	   // while(i<na && ans[i]=='0' && ++i); 
	        
	    
	   // return ans.substr(i);
	}
};
