class Solution {
public:
    int fillCups(vector<int>& a) {
        int mn=-1,ans=0;
        sort(a.begin(),a.end());
        while(a[2]>0 && a[1]>0)
        {
            a[2]--;
            a[1]--;
            ans++;
            sort(a.begin(),a.end());
        }
        while(a[2]>0){
            a[2]--;
            ans++;
        }
        return ans;
    }
};
