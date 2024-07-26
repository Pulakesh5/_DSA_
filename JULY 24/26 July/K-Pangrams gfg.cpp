class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        vector<int> count(26);
        for(char ch:str)
        {
            if(ch==' ')
                continue;
            count[ch-'a']++;
        }
            
        int unique = 0, totalCount = 0;
        for(int i=0; i<26; i++)
        {
            unique+=(count[i]>0);
            totalCount+=count[i];
        }
        int required = 26-unique;
        // cout<<required<<" "<<unique<<" "<<totalCount<<endl;
        if(required<=k && totalCount-unique>=required)
            return true;
            
        return false;
    }
};
