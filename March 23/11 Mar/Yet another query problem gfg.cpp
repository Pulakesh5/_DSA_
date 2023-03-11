vector<int> solveQueries(int N, int Q, vector<int> &A, vector<vector<int>> &Queries) {
        // code here
        map<int,vector<int>> mp;
        map<int,int> freq;
        
        for(int i=0;i<N;i++)
            freq[A[i]]++;
        
        for(int i=0;i<N;i++)
        {
            mp[freq[A[i]]].push_back(i);
            freq[A[i]]--;
        }
        
        vector<int> returnVector;
        int start, end, count;
        for(auto &query:Queries)
        {
            start = query[0];
            end = query[1];
            count = query[2];
            vector<int> indexes(mp[count]);
            auto it1 = lower_bound(indexes.begin(), indexes.end(), start);
            auto it2 = upper_bound(indexes.begin(), indexes.end(), end);
            returnVector.push_back(it2-it1);
        }
        return returnVector;
    }
