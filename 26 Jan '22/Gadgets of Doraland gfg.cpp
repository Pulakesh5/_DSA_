// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Use Hashmap
class Solution{
    public:
        static bool comp(pair<int,int> &l, pair<int,int> &r)
        {
            if (l.second != r.second) {
                return l.second > r.second;
            }
            return l.first > r.first;
        }
    vector<int> TopK(vector<int>& array, int k)
    {
        map<int,int> mp;
        int n=array.size();//number,frequency
        for(int i=0;i<n;i++){
            mp[array[i]]++;
        }
        vector<pair<int,int>> pr;
        for(auto it:mp)
            pr.push_back(it);
        sort(pr.begin(),pr.end(), comp);
        //for(auto it:pr)
        //  cout<<it.first<<" "<<it.second<<'\n';
        int i=0;
        vector<int> ans;
        while(i<k){
            ans.push_back(pr[i].first);
            i++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // } Driver Code Ends
