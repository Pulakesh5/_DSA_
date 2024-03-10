class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    vector<bool> small(26,0), cap(26,0);
	    int n = str.size();
	    string uniques = "";
	    for(int i=0; i<n; i++)
	    {
	        
	        if(str[i]>='a' && str[i]<='z' && !small[str[i]-'a'])
	        {
	            uniques.push_back(str[i]);
	            small[str[i]-'a'] = true;
	        }
	        else if(str[i]>='A' && str[i]<='Z' && !cap[str[i]-'A'])
	        {
	            cap[str[i]-'A'] = true;
	            uniques.push_back(str[i]);
	        }
	    }
	    return uniques;
	}
};
