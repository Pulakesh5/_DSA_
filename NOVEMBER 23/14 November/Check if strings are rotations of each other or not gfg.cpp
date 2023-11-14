class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int len1 = s1.size(), len2 = s2.size();
        if(len1!=len2)
            return false;
    
        string dupS1 = s1;
        dupS1+=s1;
        return dupS1.find(s2)!=string::npos;
        
    }
};
