class Solution
{
  public:
    char firstRep (string s)
    {
        //code here.
        vector<int> v(26,-1);
        int n=s.length(),first_occur=INT_MAX;
        for(int i=0;i<n;i++){
            if(v[s[i]-'a']!=-1){
                v[s[i]-'a']+=n;
                continue;
            }
            v[s[i]-'a']=i;
        }
        for(int i=0;i<26;i++)
        {
            if(v[i]<n) continue;
            first_occur=min(first_occur,v[i]%n);
        }
        return (first_occur==INT_MAX?'#':s[first_occur]);
    }
};
