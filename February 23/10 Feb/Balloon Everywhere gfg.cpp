    int maxInstance(string s){
        vector<int> count(5,0);
        int n =s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='b')
            count[0]++;
            else if(s[i]=='a')
            count[1]++;
            else if(s[i]=='l')
            count[2]++;
            else if(s[i]=='o')
            count[3]++;
            else if(s[i]=='n')
            count[4]++;
        }
        return min({count[0],count[1],count[2]/2,count[3]/2,count[4]});
    }
