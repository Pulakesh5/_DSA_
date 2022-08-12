class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string upper="",lower="";
        for(int i=0;i<n;i++){
            if(str[i]>='a' && str[i]<='z') lower+=str[i];
            else upper+=str[i];
        }
        sort(lower.begin(),lower.end());
        sort(upper.begin(),upper.end());
        
        string ans="";
        int j=0,k=0;
        for(int i=0;i<n;i++){
            ans+=(str[i]>='a' ? lower[j++]: upper[k++]);
        }
        return ans;
    }
};
