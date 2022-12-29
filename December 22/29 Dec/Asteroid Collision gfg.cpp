    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int> stk;
        
        for(int i=0;i<N;i++)
        {
            if(stk.empty() || asteroids[i]>=0)
            {
                stk.push(asteroids[i]);
                continue;
            }
            //while(!stk.empty() && (stk.top()/abs(stk.top()))!=(v[i]/abs(v[i])) && abs(stk.top()))
            if(stk.top()<0)
                stk.push(asteroids[i]);
            else
            {
                while(!stk.empty() && stk.top()>=0 && stk.top()<abs(asteroids[i]))
                    stk.pop();
                if(stk.empty() || stk.top()<0)
                    stk.push(asteroids[i]);
                else if(abs(stk.top())==abs(asteroids[i]))
                    stk.pop();
            }
        }
        vector<int> ans;
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
