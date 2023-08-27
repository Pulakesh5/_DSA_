class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
        int i=0, j=str.size() -1;
        while(i<j)
        {
            swap(str[i],str[j]);
            i++;
            j--;
        }
        return str;
    }
};
