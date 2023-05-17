    int isPossible(int n, int m, string S){
        // code here
        int x=0, y=0;
        int len = S.size();
        int xmax = 0, xmin = 0, ymax = 0, ymin = 0;
        for(int i=0;i<len;i++)
        {
            if(S[i]=='R')
                x++;
            else if(S[i]=='L')
                x--;
            else if(S[i]=='U')
                y++;
            else if(S[i]=='D')
                y--;
            xmax=max(xmax,x);
            xmin=min(xmin,x);
            ymax=max(ymax,y);
            ymin=min(ymin,y);
            // cout<<i<<" : {"<<x<<","<<y<<"} "<<xmax<<" "<<xmin<<" "<<ymax<<" "<<ymin<<endl;

        }
        // cout<<xmax<<"\n"<<xmin<<"\n"<<ymax<<"\n"<<ymin<<endl;
        return (xmax-xmin+1)<=m && (ymax-ymin+1)<=n;
        // return (rmax-lmin+1)<=m && (umax-dmin+1)<=n;
    }
