    int steppingNumbers(int n, int m)
    {
        queue<int> q;
        for(int i=0;i<10;i++) q.push(i);
        int ans=0,num, num1, num2, digit;
        while(!q.empty())
        {
            num=q.front();
            q.pop();
            if(num>=n && num<=m)
                ans++;
            if(num==0 || num>m) continue;
            
            digit=num%10;
            num1=num*10+digit-1;
            num2=num*10+digit+1;
            
            if(digit==0) q.push(num2);
            else if(digit==9) q.push(num1);
            else{
                q.push(num1);
                q.push(num2);
            }
        }
        return ans;
    }
