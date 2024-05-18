#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
/*
-----------------------------------------------

 Author : Pulakesh
 Target : CM by Sep'24
 Solution Idea :
-----------------------------------------------
*/
#pragma GCC optimize("O3,unroll-loops")
#define vll vector<ll>
#define vvll vector<vll>
#define vi vector<int>
#define vs vector<string>
#define input(a, n)             \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> a[i];            \
    }
#define vb vector<bool>
#define nl '\n';
#define ll long long
#define ull unsigned long long
#define lld long long double
#define pb emplace_back
#define ff first
#define ss second
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int set_bits(int n)
{
    return __builtin_popcount(n);
}
#define int long long int
#define nodig(N) (floor(log10(N)) + 1)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define sz(x) ((int)(x).size())
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define debug(x)        \
    cerr << #x << ": "; \
    _print(x);          \
    cerr << endl;

void _print(ll t)
{
    cerr << t;
}
// void _print(int t) {cerr << t;}
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
void _print(ull t) { cerr << t; }
void print(vector<int> a)
{
    for (auto it : a)
        cerr << it << " ";
}
const ll MOD = 1000000007;
const ll mod = 998244353;
const double eps = 1e-9;
const int MX = 1003;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    if (a == b)
        return a;
    if (a > b)
        return gcd(b, a % b);
    return gcd(b % a, a);
}
bool isprime(int num)
{
    if ((num % 2) == 0)
        return false;
    int limit = sqrt(num);
    for (int i = 3; i <= limit; i += 2)
    {
        if ((num % i) == 0)
            return false;
    }
    return true;
}
int dist(int x, int y, int lx, int ly)
{
    return abs(lx - x) + abs(ly - y);
}
ll _pow(ll n, ll p)
{
    ll res = 1;
    while (p)
    {
        if (p & 1)
            res = (res * n) % mod;
        n = (n * n) % mod;
        p /= 2;
    }
    return res;
}
/*-----------------------------CODE STARTS HERE-------------------------*/

int f(vector<vector<int>> &dp, int pos, int previous, vector<int> &both_hungry, vector<int> &either_hungry, vector<int> &both_full)
{
    int len = both_hungry.size();

    if (pos >= len)
        return 0;
    if (dp[pos][previous] != -1)
        return dp[pos][previous];
    int ans1 = 0, ans2 = 0;
    if (previous)
    {
        // feed current hare now
        ans1 = f(dp, pos + 1, 1, both_hungry, either_hungry, both_full) + either_hungry[pos];
        // feed current hare after next hare
        if (pos + 1 < len)
            ans2 = f(dp, pos + 1, 0, both_hungry, either_hungry, both_full) + both_full[pos];
        // cerr << "previous fed" << endl;
        // cerr << "Index " << pos << " : " << ans1 << ", " << ans2 << endl;
    }
    else
    {
        // feed current hare now
        ans1 = f(dp, pos + 1, 1, both_hungry, either_hungry, both_full) + both_hungry[pos];
        // feed current hare after next hare
        if (pos + 1 < len)
            ans2 = f(dp, pos + 1, 0, both_hungry, either_hungry, both_full) + either_hungry[pos];
        // cerr << "previous not fed" << endl;
        // cerr << "Index " << pos << " : " << ans1 << ", " << ans2 << endl;
    }
    return dp[pos][previous] = max(ans1, ans2);
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(2, -1));
    vector<int> both_hungry(n), either_hungry(n), both_full(n);
    input(both_hungry, n);
    input(either_hungry, n);
    input(both_full, n);

    cout << f(dp, 0, 0, both_hungry, either_hungry, both_full);
}

int32_t main()
{
    fastio();
    auto start = chrono::system_clock::now();
    {
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

        int test = 1, i = 1;
        // cin >> test;
        while (test--)
        {
            // cout<<"Case #"<<i<<": ";
            // cerr<<"\nCase #"<<i<<": \n";
            i++;
            solve();
            // cout << '\n';
        }
    }
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed = end - start;
    // cerr<<"Time taken: "<<elapsed.count()<<" sec";
    return 0;
}
