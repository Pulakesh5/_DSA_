    vector<int> findRange(string s, int n) {
        // code here
        vector<int> pos={-1,-1};
        
        int count=0,l=-1,r=-1,ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1') 
                count--;
            else if(s[i]=='0'){
                count++;
                if(l==-1) l=i+1;
            }
            
            if(count<0)
            {
                count=0;
                l=-1;
                r=-1;
            }
            if(count>ans)
            {
                r=i+1;
                ans=count;
                pos={l,r};
            }
        }
        if(pos[0]==-1 && pos[1]==-1) return {-1};
        
        return pos;
    }
