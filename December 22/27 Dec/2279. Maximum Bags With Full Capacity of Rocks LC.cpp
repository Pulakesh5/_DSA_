class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int Rocks) {
        int n=capacity.size();
        vector<int> gap(n,0);
        
        for(int i=0;i<n;i++)
            gap[i]=capacity[i]-rocks[i];

        sort(gap.begin(), gap.end());
        int i=0,MaxBags=0;
        while(i<n && gap[i]<=Rocks)
        {
            MaxBags++;
            Rocks-=gap[i++];
        }
        return MaxBags;
    }
};
