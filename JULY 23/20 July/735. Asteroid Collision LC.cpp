class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        long long sign, top, astrd;
        long long signTop, signAstrd;
        for(int asteroid:asteroids)
        {
            if(stk.empty())
            {
                stk.push(asteroid);
                continue;
            }
            sign = 1ll* stk.top() * asteroid;
            
            signTop = stk.top()/abs(stk.top());
            signAstrd = asteroid/abs(asteroid);
            astrd = abs(asteroid);
            if(!(signTop>0 && signAstrd<0))
                sign = 1;
            while((signTop>0 && signAstrd<0) && sign<0  && !stk.empty())
            {
                top = abs(stk.top());
                signTop = stk.top()/abs(stk.top());
                cout<<top<<" "<<astrd<<endl;
                if(top==astrd)
                {
                    stk.pop();
                    sign = 0ll;
                }
                else if(top>astrd)
                {
                    sign = 0ll;
                }
                else
                    stk.pop();
                cout<<sign<<endl;
                if(!stk.empty() && sign!=0)
                    sign = 1ll* stk.top() * asteroid;
            }
            if((stk.empty() && sign<0) || sign>0)
                stk.push(asteroid);
        }
        vector<int> finalAsteroid;
        while(stk.size())
        {
            finalAsteroid.insert(finalAsteroid.begin(),stk.top());
            stk.pop();
        }
        return finalAsteroid;
    }
};
