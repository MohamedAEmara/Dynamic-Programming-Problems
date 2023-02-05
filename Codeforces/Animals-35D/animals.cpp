
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;


int dp[105][10005];
int arr[110];
int n, k;

int rec(int idx, int rem)
{
    int &ret = dp[idx][rem];

    if(idx == n)
        return ret = 0;

  /*  if(rem < 0)
        return ret = -1e9;*/

    if(~ret)
    {
        return ret;
    }


    if(arr[idx] > rem)
        ret = rec(idx + 1, rem);
    else
        ret = max(rec(idx + 1, rem), 1 + rec(idx + 1, rem - arr[idx]));

    return ret;
}


signed main()
{
    fast;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>k;

    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=0;i<n;i++)
        arr[i] *= (n-i);
    
    memset(dp, -1, sizeof (dp));
    cout << rec(0, k) << endl;
}
 

