    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        //M--; N--;
        sort(X.rbegin(), X.rend());
        sort(Y.rbegin(), Y.rend());
        
        // for(auto it:X) cout<<it<<" ";
        // cout<<endl;
        // for(auto it:Y) cout<<it<<" ";
        // cout<<endl;
            
        //cout<<M<<" "<<N<<endl;
        int h=0,hcut=1;
        int v=0,vcut=1;
        int cost=0;
        
        while(h!=X.size() && v!=Y.size())
        {
            if(X[h]>Y[v])
            {
                cost += (X[h]*vcut);
                //cout<<cost<<" h="<<h<<" "<<vcut<<endl;
                h++;
                hcut++;
            }
            else
            {
                cost += (Y[v]*hcut);
                //cout<<cost<<" v="<<v+1<<" "<<hcut<<endl;
                v++;
                vcut++;
            }
        }
        while(h!=X.size())
        {
            cost += (X[h++]*vcut);
            //cout<<cost<<" h="<<h+1<<" "<<vcut<<endl;
            
        }
        while(v!=Y.size())
        {
            cost += (Y[v++]*hcut);
            //cout<<cost<<" v="<<v+1<<" "<<hcut<<endl;
        }
        
        return cost;
    }
