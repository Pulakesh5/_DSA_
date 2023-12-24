class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> vp(n);
        for(int i=0; i<n; i++)
            vp[i] = {price[i],i};
        sort(vp.begin(), vp.end());
        int stocks=0, ind=0, bought=0;
        while(k && ind<n)
        {
            bought = min(k/vp[ind].first, vp[ind].second+1);
            stocks+=bought;
            k-=(bought*vp[ind].first);
            // cout<<vp[ind].first<<" ";
            ind++;
        }
        // cout<<endl;
        return stocks;
    }
};
