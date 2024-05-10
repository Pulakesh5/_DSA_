class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,pair<int,int>>> vp;
        int len = arr.size();
        double fraction;
        for(int p1=0; p1<len; p1++)
        {
            for(int p2=p1+1; p2<len; p2++)
            {
                if(arr[p1]==arr[p2])
                    continue;
                fraction = 1.0*arr[p1];
                // cout<<fraction<<" ";
                fraction/=(1.0*arr[p2]);
                // cout<<fraction<<endl;
                vp.push_back({fraction,{arr[p1],arr[p2]}});
            }
        }
        sort(vp.begin(), vp.end());
        return {vp[k-1].second.first, vp[k-1].second.second};
    }
};
