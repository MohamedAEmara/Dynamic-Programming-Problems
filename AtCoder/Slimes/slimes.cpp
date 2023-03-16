
#include <bits/stdc++.h>
#define int long long
using namespace std;


/// ======  استعن بالله ولا تعجز  ====== ///


const int N = 405;
int n;
int arr[N];
int pre[N];
int dp[N][N];

int rec(int l, int r)
{
    if(l > r)
        return 0;
    if(l == r)
        return 0;
    int &ret = dp[l][r];
    if(~ret)
        return ret;
    int mn = 1e16;
    for(int i=l; i<r; i++)
    {
        mn = min(mn, pre[i] - pre[l] + pre[r+1] - pre[i] + rec(l, i) + rec(i+1, r));
    }
    return ret = mn;
}

signed main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    pre[0] = 0;
    for(int i=1; i<=n; i++)
        pre[i] = pre[i-1] + arr[i-1];

    memset(dp, -1, sizeof(dp));
    cout << rec(0, n-1) << endl;
}


