class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.size()!=str2.size())
            return false;
        if(str1.size()==1)
            return true;
        if(str1.size()==2)
            return str1[0]==str2[1] && str1[0]==str2[1];
        int len1=str1.size();
        bool flag = true;
        for(int i=0; i<(len1-2); i++)
        {
            if(str1[i]!=str2[i+2])
            {
                flag = false;
                break;
            }
        }
        if(flag)
            return str1[0]==
    }

};
