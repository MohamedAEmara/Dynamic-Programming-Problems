#include <bits/stdc++.h>
#define int long long
using namespace std;


// ====== استعن بالله ولا تعجز ===== //

const int COINS = 15;
const int MAX = 30005;
int coins[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
int n;
int dp[COINS][MAX];

int rec(int idx, int rem)
{
    if(rem == 0)
        return 1;

    if(rem < 0 || idx == 11)
        return 0;

    int &ret = dp[idx][rem];

    if(~ret)
        return ret;

                // Push Loop to Parameter //
    return ret = rec(idx+1, rem) + rec(idx, rem-coins[idx]);
    // leave it    --    or take one from current idx and stay at this idx.
}

signed main()
{
    double x;
    while(cin >> x)
    {   
        x *= 100;
        n = (int)x;
        if(n == 0)
            break;
        memset(dp, -1, sizeof(dp));
        int res = rec(0, n);
        cout << fixed << setprecision(2) << x/100.0 << setw(16) << res << endl;
    }
}