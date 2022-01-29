
// Using extra space
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    {
        
        int n=S.length();
    	unordered_map<int, string> mp;
    	int word = 0, pos=0;
    	string token="";
    	for(int i = 0; i < n; i++){
            if( S[i] == '.' ){
    	     	mp[word++] = token;
    		    token = "";
            }
            else{
          	    token += S[i];
            }
        }
        if(token!="")
            mp[word++]=token;
        string ans="";
        for( int i = word - 1; i > 0; i-- ){
        	ans += mp[i];
        	ans+='.';
        }
        ans+=mp[0];
    	return ans;
    	
    } 
};

//In-Place reversal method

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    {
        reverse(S.begin(), S.end());
        cout<<S<<'\n';
        int i = 0;
        while(i < S.length()){
            int j = i;
            while(j < S.length() && S[j] != '.'){
                j++;
            }
            reverse(S.begin() + i, S.begin() + j);
             cout<<S<<'\n';
            i = j + 1;
        }
        return S;
    } 
};
        
       
