#define pb push_back
class Solution{   
public:
    long long int nineDivisors(long long int N){
        //Code Here
        
        long long lim=sqrt(N);
        vector<bool> notPrime(lim+1,false);
        for(int i=4;i<=lim;i+=2)
            notPrime[i]=true;
        
        for(int i=3;(i*i)<=lim;i+=2){
            for(int j=i*i;j<=lim;j+=i){
                notPrime[j]=true;
            }
        }
        vector<long long> Primes;
        Primes.pb(2);
        for(int i=3;i<=lim;i+=2)
            if(!notPrime[i]) 
                Primes.pb(i);
                
        int f=sqrt(sqrt(lim)); // n^8
        long long count = upper_bound(Primes.begin(), Primes.end(), f) - Primes.begin();
        
        // for(int i=0;i<=count;i++) cout<<Primes[i]<<" ";
        //  cout<<endl;
        for(int i=0;i<Primes.size();i++){
            for(int j=i+1;j<Primes.size();j++)
            {
                if(Primes[i]*Primes[j] > lim) break;
                //cout<<"[ "<<Primes[i]<<", "<<Primes[j]<<" - "<<Primes[i]*Primes[j]<<" ], ";
                //cout<<Primes[i]*Primes[j]<<" "; 
                count++;
            }
            //cout<<endl;
        }
        return count;
    }
};
