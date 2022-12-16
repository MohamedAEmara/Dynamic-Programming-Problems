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
int arr[100005];
int dp[100005];

int rec(int idx)
{
    if(idx == n-1)
        return 0;
    int &ret = dp[idx];
    if(~ret)
        return ret;
    if(idx == n-2)
        ret = abs(arr[idx+1] - arr[idx]) + rec(idx+1);
    else
        ret = min(abs(arr[idx+1] - arr[idx]) + rec(idx+1) , abs(arr[idx+2] - arr[idx]) + rec(idx+2));
    return ret;
}


signed main()
{
    fast;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof dp);
    cout << rec(0) << endl;
}

