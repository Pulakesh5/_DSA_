class Solution{
public:
    int max_non_overlapping( vector< vector<int> >& ranges )
    {
        int n=ranges.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i]={ranges[i][1],ranges[i][0]};
        }
        sort(vec.begin(),vec.end());//,comp);
        
        int ending=vec[0].first;
        int count=1;
        for(int i=1;i<n;i++){
            if(vec[i].second>=ending)
                {
                    count++;
                    ending=vec[i].first;
                }
        }
        return count;
        
    }
};
