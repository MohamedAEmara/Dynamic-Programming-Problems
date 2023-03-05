
#include <bits/stdc++.h>
#define int long long
using namespace std;


// ====== استعن بالله ولا تعجز ===== //

const int COINS = 15;
const int MAX = 30005;
//int coins[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
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

    ret = rec(idx+1, rem);      // leave it.

    while(rem - coins[idx] >= 0)        // can I take a coin of the current remaining?
    {
        ret += rec(idx+1, rem-coins[idx]);      // take one of that coin and see How many ways of the new remaining.
        rem -= coins[idx];
    }       // loop till I can't take anymore of that coin

    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double x;
    while(cin >> x)
    {
        x *= 100;
        x = round(x);
        n = (int)x;
        if(n == 0)
            break;
        memset(dp, -1, sizeof(dp));
        int res = rec(0, n);
        cout << setw(6) << fixed << setprecision(2) << x/100.0 << setw(17) << res << endl;
    }
}


