class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
        vector<int> freq(26,0);
	    for(char ch:s)
	        freq[ch-'a']++;
	    int maxi = *max_element(freq.begin(), freq.end());
	    
	    int val =0 , cnt=0, cnt1=0;
	    
	    for(int i=0; i<26; i++)
	    {
	        if(freq[i]!=0)
	        {
	            if(freq[i]<maxi)
	            {
	                cnt1++;
	                if(val==0)
	                    val = freq[i];
	                else if(freq[i]!=val)
	                    return false;
	            }
	            else 
	                cnt++;
	        }
	    }
	    
	   // cout<<cnt<<" "<<cnt1<<endl;
	   // cout<<maxi<<" "<<val<<endl;
	    
	    if((cnt>1 && cnt1>1) || (cnt==1 && cnt1>1 && maxi-val>1) || (cnt1==1 && cnt>1 && val!=1) || (cnt1==1 && cnt==1 && maxi-val>1))
	        return false;
	    return true;
	}
};
