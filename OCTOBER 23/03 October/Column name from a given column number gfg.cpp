class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string col = "";
        int c;
        while(n)
        {
            c = (n%26);
            if(c==0)
                c = 26;
            n-=c;
            col.push_back(c-1+'A');
            n/=26;
        }
        reverse(col.begin(), col.end());
        return col;
    }
};
