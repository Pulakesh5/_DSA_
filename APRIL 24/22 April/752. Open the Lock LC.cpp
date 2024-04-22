class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        vector<int> visited(10005,0);

        for(string str:deadends)
        {
            int num = stoi(str);
            visited[num] = -1;
        }
        if(visited[0]==-1)
            return -1;
        queue<string> q;
        q.push("0000");
        visited[0] = 1;

        int qsize = 0, turns = 0, num;
        string nextCombn;
        while(!q.empty())
        {
            qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                string combn = q.front();
                q.pop();
                if(combn==target)
                    return turns;
                for(int k=0; k<4; k++)
                {
                    
                    if(combn[k]>='1' && combn[k]<='8')
                    {
                        nextCombn = combn;
                        nextCombn[k] = combn[k]+1;
                        num = stoi(nextCombn);
                        if(visited[num]==0)
                        {
                            q.push(nextCombn);
                            visited[num] = 1;
                        }
                        nextCombn[k] = combn[k]-1;
                        num = stoi(nextCombn);
                        if(visited[num]==0)
                        {
                            q.push(nextCombn);
                            visited[num] = 1;
                        }
                    }
                    else if(combn[k]=='0')
                    {
                        nextCombn = combn;
                        nextCombn[k] = '1';
                        num = stoi(nextCombn);
                        if(visited[num]==0)
                        {
                            q.push(nextCombn);
                            visited[num] = 1;
                        }
                        nextCombn[k] = '9';
                        num = stoi(nextCombn);
                        if(visited[num]==0)
                        {
                            q.push(nextCombn);
                            visited[num] = 1;
                        }
                        
                    }
                    else if(combn[k]=='9')
                    {
                        nextCombn = combn;
                        nextCombn[k] = '8';
                        num = stoi(nextCombn);
                        if(visited[num]==0)
                        {
                            q.push(nextCombn);
                            visited[num] = 1;
                        }
                        nextCombn[k] = '0';
                        num = stoi(nextCombn);
                        if(visited[num]==0)
                        {
                            q.push(nextCombn);
                            visited[num] = 1;
                        }
                        
                    }
                }
            }
            turns++;
        }
        return -1;
    }
};
