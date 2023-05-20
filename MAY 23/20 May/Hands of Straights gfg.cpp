    bool isStraightHand(int N, int groupSize, vector<int> &hands) {
        // code here
        
        if(N%groupSize != 0) return false;
        
        int groups = N/groupSize;
        vector<int> lastCard(groups);
        map<int,int> mp;
        for(int i=0; i<N; i++) mp[hands[i]]++;
        
        while(!mp.empty())
        {
            int beg=mp.begin()->first;
            int count=0;
            for(int i=0;i<groupSize;i++)
            {
                if(mp[beg]){
                    mp[beg]--;
                    count++;
                    }
                if(!mp[beg])
                    mp.erase(beg);
                beg=beg+1;
            }
            if(count!=groupSize)
                return false;
        }
        return true;
    }
