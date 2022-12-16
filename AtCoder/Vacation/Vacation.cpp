
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/

int n;
int a[100005];
int b[100005];
int c[100005];
int dp[100005][4];

int rec(int idx, int color)
{
    if(idx == n)
        return 0;
    int &ret = dp[idx][color];

    if(~ret)
        return ret; 
    
    if(color != 1)
        ret = max(ret, a[idx+1] + rec(idx+1, 1));
    if(color != 2)
        ret = max(ret, b[idx+1] + rec(idx+1, 2));
    if(color != 3)
        ret = max(ret, c[idx+1] + rec(idx+1, 3));

    return ret;
}

signed main()
{
    fast;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i] >> b[i] >> c[i];
    memset(dp, -1, sizeof dp);
    cout << rec(0, 0) << endl;
}


