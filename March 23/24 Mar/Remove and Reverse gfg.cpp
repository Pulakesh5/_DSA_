string removeReverse(string S) {
        // code here
        vector<int> freq(26,0);
        for(char ch:S)
            freq[ch-'a']++;
        string front="", back="";
        bool flag=true;
        int i=0, j=S.size()-1;
        int removal=0;
        while(i<=j)
        {
            
            if(flag)
            {
                
                if(freq[S[i]-'a']>1)
                {
                    freq[S[i]-'a']--;
                    flag=false;
                }
                else
                    front.push_back(S[i]);
                //cout<<i<<" "<<S[i]<<" "<<front<<endl;
                i++;
            }
            else
            {
                
                if(freq[S[j]-'a']>1)
                {
                    freq[S[j]-'a']--;
                    flag=true;
                }
                else
                    back.push_back(S[j]);
                //cout<<j<<" "<<S[j]<<" "<<back<<endl;
                j--;
            }
        }
        
        reverse(back.begin(), back.end());
        string ans=front+back;
        
        if(!flag)
            reverse(ans.begin(),ans.end());
        
        return ans;
    }
