
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define MohamedEmara ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
    استعن بالله ولا تعجز
*/

int n, m;
const int MAX_N = 5005;
int arr[MAX_N];
int dp[MAX_N][MAX_N];

int LIS(int idx, int last)
{
    // Base Case:
    if(idx == n+1)
        return 0;

    // Memoization:
    int &ret = dp[idx][last];
    if(~ret)
        return ret;

    ret = LIS(idx+1, last);                         // leave
    if(arr[idx] >= arr[last])                           // can take
        ret = max(ret, 1 + LIS(idx+1, idx));    // max(leave, take)

    return ret;
}

signed main()
{
    MohamedEmara;

    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        double blablabla;
        cin >> arr[i] >> blablabla;
    }

    // IDEA
    // There are some indices need to be changed
    // We can calculate the max indices can be in their right places
    // the other indices need to be changed --> so the result will be
    // res = all_elements - max_elements_in_their_right_places.

    memset(dp, -1, sizeof(dp));
    int mx = 0;
    for(int i=1; i<=n; i++)
    {
        mx = max(mx, LIS(i, i));
    }
    cout << n - mx << endl;

}


