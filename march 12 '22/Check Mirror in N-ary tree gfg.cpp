class Solution {
  public:
    int checkMirrorTree(int n, int e, int a[], int b[]) {
        unordered_map<int, stack<int>> mp;
        //int a,b;
        for(int i=0;i<(2*e);i+=2){
            //cin>>a>>b;
            mp[a[i]].push(a[i+1]);
        }
        for(int i=0;i<(2*e);i+=2){
            if(mp[b[i]].top()!=b[i+1])
                return 0;
            mp[b[i]].pop();
        }
        return 1;
    }
};
