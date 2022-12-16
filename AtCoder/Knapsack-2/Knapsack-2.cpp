
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/

int n, k;
int w[105];
int v[105];
int mem[105][100005];

int rec(int idx, int rem_value)
{
    if(idx == n+1)
    {
        if(rem_value > 0)
            return 1e18;
        else
            return 0;
    }

    int &ret = mem[idx][rem_value];
    if(~ret)
        return ret;

    ret = rec(idx+1, rem_value);     // leave it
    if(rem_value - v[idx] >= 0)  // can take
        ret = min(ret, rec(idx+1, rem_value - v[idx]) + w[idx]);

    return ret;
}

signed main()
{
    fast;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> w[i] >> v[i];
    memset(mem, -1, sizeof mem);
    // max value I can get if
    //      n = max_n = 100
    //   && v = max_v = 1000;
    //  then  sum_values = 1000*100 = 100000
    // loop from 0 to 100000 and find the max valid value I can get

    int mx = 0;
    for(int i=0;i<=100000;i++)
    {
        // if this value is valid --> maxmize the mx

        if(rec(1, i) <= k)
        {
            mx = max(i, mx);
        }
    }
    cout << mx << endl;

}


