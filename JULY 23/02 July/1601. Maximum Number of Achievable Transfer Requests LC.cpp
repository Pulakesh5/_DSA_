class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        // int buildings[n];
        vector<int> buildings(n);
        int req = requests.size(), setBits = 0, flag = 1;
        int achievableRequest = 0;
        for(int mask = 0; mask<(1<<req); mask++)
        {
            setBits = 0;
            flag = 1;
            // memset(buildings, 0, n);
            fill(buildings.begin(), buildings.end(), 0);
            for(int i=0; i<req; i++)
            {
                if(mask & (1<<i))
                {
                    buildings[requests[i][0]]--;
                    buildings[requests[i][1]]++;
                    setBits++;
                }
            }
            // cout<<mask<<" : "<<setBits<<" ";
            for(int i=0; i<n ; i++)
            {
                // cout<<buildings[i]<<" ";
                if(buildings[i]!=0)
                    flag = 0;
            }
            // cout<<" \t"<<flag<<endl;
            if(flag)
               achievableRequest = max(achievableRequest, setBits); 
        }
        // backtrack(requests, buildings, 0, 0);
        return achievableRequest;
    }
};
