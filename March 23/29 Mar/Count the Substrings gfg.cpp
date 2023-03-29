    int countSubstring(string S)
    {
        // code here
        int count=0, n=S.size();
        int low, up;
        for(int i=0;i<n;i++)
        {
            low=0;
            up=0;
            for(int j=i;j<n;j++)
            {
                low+=(islower(S[j])>0);
                up+=(isupper(S[j])>0);
                if(low==up)
                    count++;
                //cout<<i<<" "<<j<<' '<<low<<' '<<up<<" "<<count<<endl;
            }
            
        }
        return count;
    }
