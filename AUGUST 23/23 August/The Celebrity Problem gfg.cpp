class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int knows, knownTo;
        for(int person=0; person<n; person++)
        {
            knows=0;
            knownTo=0;
            for(int i=0; i<n; i++)
            {
                knows+=M[person][i];
                knownTo+=M[i][person];
            }
                
            if(knows==0 && knownTo==(n-1))
                return person;
        }
        return -1;
    }
};
