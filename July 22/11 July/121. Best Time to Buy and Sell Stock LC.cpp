class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int buy=INT_MAX,profit=0;
        for(int i=0;i<n;i++){
           if(a[i]<buy) buy=a[i];
            else if(a[i]-buy>profit) profit=a[i]-buy;
        }
        return profit;
    }
};
auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
