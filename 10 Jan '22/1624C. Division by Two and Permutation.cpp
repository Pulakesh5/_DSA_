#include<bits/stdc++.h>
using namespace std;
/*
-----------------------------------------------
  
  Author : Pulakesh
 Problem Link:https://codeforces.com/contest/1624/problem/C
-----------------------------------------------
*/

#define vll vector<ll>
#define vvll  vector<vll>
#define vi  vector<int>
#define vs  vector<string>
#define input(a,n) for(int i=0;i<n;i++) {int x; cin>>x;a.pb(x);}
#define vb  vector<bool>
#define nl '\n';
#define ll long long
#define pb emplace_back
#define F first
#define S second
//#define int long long int
#define nodig(N)  (floor(log10(N)) + 1)
#define forn(i,n) for(int i=0;i<(int)n; i++)
const ll MOD=  998244353;
const double eps = 1e-9;
const int MX = 1e9+1;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
//bitlate<typename T> oneoid get(T* a, ll n){ for(ll i = 0; i < n; i++) cin>>a[i]; } bitlate<typename T> oneoid get(oneector<T>& a, ll n){ for(ll i = 0; i < n; i++) cin>>a[i]; } bitlate<typename T> oneoid get(T* a, T* b, ll n){ for(ll i = 0; i < n; i++) cin>>a[i]>>b[i]; } bitlate<typename T> oneoid get(oneector<T>& a, oneector<T>& b, ll n){ for(ll i = 0; i < n; i++) cin>>a[i]>>b[i]; } bitlate<typename T> oneoid get(T** a, ll n, ll m){ for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cin>>a[i][j]; } bitlate<typename T> oneoid get(oneector<oneector<T>>& a, ll n, ll m){ for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cin>>a[i][j]; } bitlate <class ...Args> oneoid get(Args &...args){ (cin >> ... >> args); }
 void print(vector<vector<int>> a, ll n, ll m){ for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cout<<a[i][j]; }
ll sum(ll n) {return (n*(n+1))/2.0;}
ll len( string str) { return str.length();}
ll fact(ll n){ if(n>0) return ((n%MOD)*fact(n-1))%MOD; else return 1;}
bool solve(void);

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
bool sortbysec(const pair<string,int> &a,const pair<string,int> &b){return (a.second > b.second);}
vi primes;
void primeFactors(int n, set<int> &st) 
{ 
    // Print the number of 2s that divide n 
    while (n%2 == 0) 
    { 
        st.insert(2);
        n = n/2; 
    } 
     
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            st.insert(i); 
            n = n/i; 
        } 
    } 
     
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2) 
        st.insert(n); 
}
struct comp1 {
    template <typename T>
  
    bool operator()(const T& l,
                    const T& r) const
    {
        if (l.first.first != r.first.first) {
            return l.first.first < r.first.first;
        }

        return l.second <= r.second;
    }
};
struct comp2 {
    template <typename T>
  
    bool operator()(const T& l,
                    const T& r) const
    {
        if (l.first.first != r.first.first) {
            return l.first.first < r.first.first;
        }

        return l.second >= r.second;
    }
};
bool solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(all(arr));
    int ind=n-1;
    bool flag=false;
    while(ind>=0){
        if(arr[ind]==ind+1){
            ind--; continue;
        }

        for(int j=ind;j>=0 && !flag;j--)
        {
            int x=arr[j];
            while(x>0)
            {
                if(x==ind+1){
                    arr[j]=x;
                    swap(arr[j],arr[ind]);
                    flag=true;
                    break;
                }
                x/=2;
            }
        }
        if(!flag){
             cout<<"NO"; return 0;
        }
        flag=false;
        ind--;
    }
    cout<<"YES";
    return 0;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //primes=sieve();
    auto start=chrono::system_clock::now();
    {
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w",stdout);
        #endif //ONLINE_JUDGE
        
        int test=1,i=1;
        cin>>test;
        while(test--){
            cerr<<"Case #"<<i++<<": \n";
            solve();
            cout<<'\n';
        }
    }
    auto end=chrono::system_clock::now();
    chrono::duration<double> elapsed=end-start;
    //cerr<<"Time taken: "<<elapsed.count()<<" sec";   
    return 0; 
    
}
