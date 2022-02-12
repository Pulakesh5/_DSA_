// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxEvents(int start[], int end[], int n) {
        pair<int,int> meet[n];
        for(int i=0;i<n;i++)
        {
            meet[i].first=start[i];
            meet[i].second=end[i];
        }
        sort(meet,meet+n);
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans=0,i=0;
        for(int d=1;d<=100000;d++){ // traversing over d from 1to 100000
            while(pq.size() && pq.top()<d) // removing events from queue that ended before d
                pq.pop();
            while(i<n && meet[i].first==d) // adding events to queue that are starting on d
                pq.push(meet[i++].second);
            if(pq.size()>0) // if any event is ongoing on day dand it is not selected then select that,pop that and ans++
            {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];

        Solution ob;
        cout << ob.maxEvents(start,end,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
