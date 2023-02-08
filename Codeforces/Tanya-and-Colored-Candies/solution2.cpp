
#include <bits/stdc++.h>
#define int long long
#define MohamedEmara ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/
int n, m, k;
string s;
int arr[55];
int dp[55][2010];   // idx rem 
bool vis[55];

int rec(int idx, int rem, char last, int val)
{
    // Invalid case
    if(idx<0 or idx>=n) {
        return 1e15;
    }

    // Base case
    if(rem <= 0) {
        return 0;
    }

    int &ret = dp[idx][rem];
    if(~ret)
        return ret;

    int mn = 1e15;

    for(int i=0; i<idx; i++)
    {
        if(last != s[i] and arr[i] > val){
            mn = min(mn, idx-i + rec(i, rem-arr[i], s[i], arr[i]));
        }
    }

    for(int i=idx+1; i<n; i++)
    {
        if(last != s[i] and arr[i] > val){
            mn = min(mn, i-idx + rec(i, rem-arr[i], s[i], arr[i]));
        }
    }


    vis[idx] = 1;
    return ret = mn;
}

signed main()
{
    MohamedEmara;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cin >> s;

    vis[m-1] = 1;
    int res = 1e15;
    for(int i=0; i<n; ++i)
    {
        memset(dp, -1, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        // assume every start point
        // and calculate the cost to get that point.
        int haha = abs(i - (m-1)) + rec(i, k-arr[i], s[i], arr[i]);
        res = min(res, haha);
    }

    if(res >= 1e15)
        cout << -1 << endl;
    else
        cout << res << endl;

}

