
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

int rec(int idx, int rem)
{
    if(idx == n+1)
        return 0;

    int &ret = mem[idx][rem];
    if(~ret)
        return ret;

    if(rem >= w[idx])
    {
        int leave = rec(idx+1, rem);
        int take = v[idx] + rec(idx+1, rem - w[idx]);
        ret = max(leave, take);
    }
    else
        ret = rec(idx+1, rem);

    return ret;
}

signed main()
{
    fast;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> w[i] >> v[i];
    memset(mem, -1, sizeof mem);
    cout << rec(1, k) << endl;
}


