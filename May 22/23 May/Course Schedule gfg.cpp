/*
Try thinking in terms of graphs how the courses are connected which is depending upon on what
then can use any graph traversal method
*/

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> indegree(n,0),ans;
        vector<vector<int>> allow(n);
        for(auto &pr:prerequisites){
            allow[pr[1]].push_back(pr[0]);
            indegree[pr[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
                //cout<<indegree[i]<<" ";
        }
        //cout<<endl;
    
        while(!q.empty()){
            int cur_course=q.front();
            //cout<<cur_course<<" ";
            q.pop();
            for(auto &it:allow[cur_course]){
                //cout<<"it "<<it<<endl;
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
            ans.push_back(cur_course);
        }
        //cout<<endl;
        if(ans.size()!=n) return {};
        return ans;
    }
};
