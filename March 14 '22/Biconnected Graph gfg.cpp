class Solution {
  public:
    int biGraph(int arr[], int n, int e) {
        if(n==1) return 1;
        if(n==2 && e==1) return 1;
        unordered_map<int,vector<int>> p;
        for(int i=0;i<(2*e);i+=2){
            p[arr[i]].push_back(arr[i+1]);
            p[arr[i+1]].push_back(arr[i]);
        }
        for(auto m:p){
            if(m.second.size()<2){  // here < 2 means only one adjacent node,
                                    //if that node is removed then this node would be disconnected
                return 0;
            }
        }
        return 1;    
    }
};
