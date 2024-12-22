#include <bits/stdc++.h>
using namespace std;

int M, N;
vector<vector<int>> tshirts(101);
long long dp[101][(1 << 10) + 1];
long long MOD = 1e9 + 7;

long long solve(int tshirt, int mask)
{
    if (tshirt == 101)
        return (__builtin_popcount(mask) == N);

    if (dp[tshirt][mask] != -1)
        return dp[tshirt][mask];
    long long count = solve(tshirt + 1, mask);

    for (int has : tshirts[tshirt])
    {
        if (!(mask & (1 << has)))
            count = (count + solve(tshirt + 1, mask + (1 << has))) % MOD;
    }
    return dp[tshirt][mask] = count;
}
int main()
{
    // your code goes here
    int TC;
    cin >> TC;
    // cout << TC << endl;
    while (TC--)
    {
        int n;
        cin >> n;
        // cout << "Testcase " << TC << " " << n << endl;
        N = n;
        string line, ts;
        getline(cin, line);

        for (int i = 0; i <= 100; i++)
            tshirts[i].clear();
        for (int i = 0; i < n; i++)
        {
            getline(cin, line);
            stringstream ss(line);
            while (ss >> ts)
                tshirts[stoi(ts)].push_back(i);
        }

        // for (int i = 0; i <= 100; i++)
        // {
        //     if (tshirts[i].size())
        //     {
        //         cout << i << " : ";
        //         for (int ts : tshirts[i])
        //             cout << ts << " ";
        //         cout << endl;
        //     }
        // }
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0) << endl;
    }
}
