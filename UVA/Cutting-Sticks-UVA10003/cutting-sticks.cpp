
#include <bits/stdc++.h>
#define ing long long
using namespace std;


int len, n;
int arr[55];
int dp[55][55];


int rec(int start, int end, int l, int r)
{
    if(start == end || l > r)
        return 0;

    int &ret = dp[l][r];
    if(~ret)
        return ret;
    
    ret = INT_MAX;
    for(int i=l; i<=r; i++)
    {
        int tmp_cost = end - start + 1;
        // choose the best index to cut now.
        // that results in two other segments (l -> i-1) & (i+1 -> r)
        ret = min(ret, tmp_cost + rec(start, arr[i], l, i-1) + rec(arr[i]+1, end, i+1, r));
    }

    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> len)
    {
        if(len == 0)
            return 0;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << "The minimum cutting is " << rec(1, len, 0, n-1) << ".\n";
    }
}


