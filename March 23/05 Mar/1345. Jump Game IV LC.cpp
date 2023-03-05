class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n=arr.size();
        
        unordered_map<int, vector<int>> indice;
        vector<bool> visited(n,false);
        
        for(int i=0; i<n; i++) 
            indice[arr[i]].push_back(i);
        queue<int> q; q.push(0);
        visited[0]=true;
       
        int step=0;
        while(!q.empty()){
            for(int i=q.size(); i>0;--i){
                int frnt=q.front(); q.pop();
                
                if(frnt == n-1) return step;
                vector<int>& next=indice[arr[frnt]];
                next.push_back(frnt-1);
                next.push_back(frnt+1);
                
                for(auto t:next){
                    if(t>=0 && t<n && !visited[t]){
                        q.push(t);
                        visited[t]=true;
                    }
                }
                next.clear();
            }
            step++;
        }
        return 0;
    }
};
