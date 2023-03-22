    vector<long long> count(string S, char ch1, char ch2)
    {
        stack<char> stk1, stk2;
        stk1.push(S[0]);
        int n=S.size();
        vector<long long> counts;
        long long count1=0, count2=0;
        for(int i=1;i<n;i++)
        {
            if(!stk1.empty() && stk1.top()==ch1 && S[i]==ch2)
            {
                stk1.pop();
                count1++;
            }
            else
                stk1.push(S[i]);
        }
        // cout<<ch1<<" "<<ch2<<'\n'<<count1<<" "<<count2<<endl;
        
            // cout<<stk1.top()<<" ";
            stk2.push(stk1.top());
            stk1.pop();

        
        while(!stk1.empty())
        {
            // cout<<stk1.top()<<" ";
            if(!stk2.empty() && stk2.top()==ch1 && stk1.top()==ch2)
            {
                stk2.pop();
                count2++;
            }
            else
                stk2.push(stk1.top());
            stk1.pop();
        }
        
        if(ch1=='r')
        {
            counts.push_back(count1);
            counts.push_back(count2);
        }
        else
        {
            counts.push_back(count2);
            counts.push_back(count1);
        }
        // cout<<"\n"<<count1<<" "<<count2<<endl;
        return counts;
    }
    long long solve(int X,int Y,string S){
      //code here
        stack<char> stk;
        vector<long long> amount1, amount2;
        
        amount1 = count(S,'p','r');
        
        amount2 = count(S,'r','p');
        return max(amount1[0]*Y+amount1[1]*X, amount2[0]*Y+amount2[1]*X);
    }
