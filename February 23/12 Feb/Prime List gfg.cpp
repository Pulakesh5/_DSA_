    void generatePrimes(vector<int> &primes)
    {
        int lim=20000;
        vector<bool> isPrime(20005,true);
        
        for(int i=2;i<=sqrt(lim);i++)
        {
            if(isPrime[i])
            {
                for(int j=i*i;j<=lim;j+=i)
                {
                    isPrime[j]=false;
                }
            }
        }
        
        for(int i=2;i<=lim;i++)
        {
            if(isPrime[i])
                primes.push_back(i);
        }
    }
    
    Node *primeList(Node *head)
    {
        vector<int> primes;
        generatePrimes(primes);
        
        Node* root = head;
        Node* answer = root;
        int val;
        while(root)
        {
            auto it = lower_bound(primes.begin(), primes.end(), root->val);
            val = root->val;
            if((*it)!=val)
            {
                if(it==primes.begin())
                    root->val=*it;
                else if( ((*it)-val) < (val-*(--it)) )
                    root->val = *(++it);
                else
                    root->val = *it;
            }
            root = root->next;
        }
        //cout<<endl;
        return answer;
        
    }
