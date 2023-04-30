map<int,int> m;
        for(auto i: intervals){
            m[i[0]]++;
            m[i[1]+1]--;
        }
        int count=0,pcount=-1,ans=-1;
        for(auto i: m){
            count+=i.second;
            if(count>=k)
                ans=i.first;
            else if(pcount>=k)
                ans=i.first-1;
            pcount=count;
        }
        return ans;
