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
int arr[100005];
int dp[100005];

int rec(int idx)
{
    if(idx == n-1)
        return 0;
    int &ret = dp[idx];
    if(~ret)
        return ret;
    ret = 1e15;
    for(int i=1; (i<=k && i+idx<=n-1); i++)
    {
        ret = min(ret, abs(arr[idx] - arr[idx+i]) + rec(idx+i));
    }
    return ret;
}


signed main()
{
    fast;
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof dp);
    cout << rec(0) << endl;
}

