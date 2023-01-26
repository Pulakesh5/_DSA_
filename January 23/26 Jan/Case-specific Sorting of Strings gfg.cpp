//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        // your code here
        string lower="", upper="";
        
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a' && s[i]<='z')
                lower.push_back(s[i]);
            else
                upper.push_back(s[i]);
        }
        
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());
        string sorted="";
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                sorted.push_back(lower.back());
                lower.pop_back();
            }
            else
            {
                sorted.push_back(upper.back());
                upper.pop_back();
            }
        }
        
        reverse(sorted.begin(), sorted.end());
        
        return sorted;
    }
};
