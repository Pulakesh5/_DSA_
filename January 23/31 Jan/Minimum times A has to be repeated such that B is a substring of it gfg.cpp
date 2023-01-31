    int minRepeats(string A, string B) {
        // code here
        string lngstr="";
        int count=0;
        while(lngstr.size()<B.size())
        {
            lngstr+=A;
            count++;
        }
        if(lngstr.find(B)!=-1) return count;
        lngstr+=A;
        count++;
        if(lngstr.find(B)!=-1) return count;
        return -1;
    }
