    set<int> primes;
    
    void prime(void)
    {
        int lim=10005;
        vector<bool> nums(lim,true);
        
        for(int i=2;i<=sqrt(lim);i++)
        {
            if(nums[i])
            {
                for(int j=i*i;j<=lim;j+=i)
                    nums[j]=false;
            }
        }
        
        for(int i=1001;i<lim;i++)
        {
            if(nums[i])
            primes.insert(i);
        }
        
    }
    int shortestPath(int Num1,int Num2)
    {   
        // Complete this function using prime vector
        prime();
        
        
        vector<int> visited(10005,0);
        queue<int> q;
        q.push(Num1);
        visited[Num1]=1;
        int step=0,tmp;
        
        while(!q.empty())
        {
            int qs=q.size();
            for(int i=0;i<qs;i++)
            {
                
                int num=q.front();
                // cout<<num<<" ";
                q.pop();
                if(num==Num2) return step;
                
                string nums=to_string(num);
                
                for(int pos=0;pos<4;pos++)
                {
                    char pre=nums[pos];
                    for(int j=0;j<=9;j++)
                    {
                        if((pre-'0')==j) continue;
                        
                        nums[pos]=(j+'0');
                        tmp=stoi(nums);
                        //cout<<tmp<<" ";
                        if(primes.find(tmp)!=primes.end() && visited[tmp]==0)
                        {
                            
                            q.push(tmp);
                            visited[tmp]=1;
                        }
                    }
                    nums[pos]=pre;
                }
            }
            step++;
            //cout<<endl;
        }
        
        return -1;
    }
