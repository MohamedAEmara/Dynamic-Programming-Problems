
#include <bits/stdc++.h>
#define int long long
#define endl '\n';
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


// ====== استعن بالله ولا تعجز ====== //



signed main()
{
    fast;
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int pre[n+1];
    pre[0] = 0;
    for(int i=0; i<n; i++)
    {
        pre[i+1] = pre[i] + arr[i];
    }

    // dp[last][rem]
    // at every dp[last][rem]
    // maximize the value 


    // base case:
    // for every rem = 0  --->  dp[idx][0] = 0;

    // for every idx >= n ----> dp[n][rem] = 0;

    int dp[n+10][k+1];
    memset(dp, -1, sizeof(dp));
    for(int idx = 0; idx<n; idx++)
    {
        dp[idx][0] = 0;
    }

    for(int rem=0; rem<=k; rem++)
    {
        dp[n][rem] = 0;
    }


    for(int idx=n-1; idx>=0; idx--)
    {
        for(int rem = 1; rem <= k; rem ++)
        {
            // leave = move to the next idx with the same rem
            // take  = move to the next idx, add the value of this pre[idx] - pre[idx+m], and decrement rem
            int leave = dp[idx+1][rem];
            int take = 0;
    
            if(idx + m - 1 < n ){
                take = abs(pre[idx+m] - pre[idx]) + dp[idx+m][rem-1];
            }
            dp[idx][rem] = max(leave, take);
        }
    }

 
    // The result is at index=0 & rem = k ==> dp[0][k]
    cout << dp[0][k] << endl;
}



