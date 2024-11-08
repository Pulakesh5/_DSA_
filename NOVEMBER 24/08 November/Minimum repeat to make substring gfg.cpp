class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        string r=s1;
        int count = 1;
        while(s1.size()<s2.size())
        {
            s1+=r;
            count++;
        }
        if(s1.find(s2)!=-1)
            return count;
        s1+=r;
        count++;
        if(s1.find(s2)!=-1)
            return count;
        return -1;
    }
};
