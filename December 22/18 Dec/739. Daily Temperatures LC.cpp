class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        stack<int> stk;
        
        int n=temp.size();
        
        vector<int> next(n);

        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() && temp[stk.top()]<=temp[i])
            {
                //cout<<"T:"<<temp[i]<<" top:"<<stk.top()<<endl;
                stk.pop();
            }
            
            if(stk.empty()) next[i]=0;
            else    next[i]=stk.top()-i;

            //cout<<i<<" "<<stk.size()<<endl;

            stk.push(i);

            //cout<<i<<" "<<stk.size()<<endl;
            //cout<<endl;
        }

        return next;
    }
};
