class Solution{   
public:
    bool isPrime(string str)
    {
        int num = stoi(str);
        int lim = sqrt(num);
        for(int d=2; d<=lim+1; d++)
        {
            if(num%d==0)
                return false;
        }
        return true;
    }
    int solve(int num1,int num2)
    {   
      //code here
        string str1=to_string(num1), str2=to_string(num2);
        int step=0, qsize;
        string newNum;
        queue<string> q;
        q.push(str1);
        set<string> visited;
        visited.insert(str1);
        
        while(!q.empty())
        {
            qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                string num = q.front();
                q.pop();
                if(num==str2)
                    return step;
                for(int i=0; i<4; i++)
                {
                    int prevDigit = num[i]-'0';
                    for(int digit=(i==0?1:0); digit<10; digit++)
                    {
                        if(digit==prevDigit)
                            continue;
                        newNum = num;
                        newNum[i] = (digit+'0');
                        if(isPrime(newNum) && visited.find(newNum)==visited.end())
                        {
                            visited.insert(newNum);
                            q.push(newNum);
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
