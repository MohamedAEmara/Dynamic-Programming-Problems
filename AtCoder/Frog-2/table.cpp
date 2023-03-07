
#include <bits/stdc++.h>
#define int long long
#define endl '\n';
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


// ====== استعن بالله ولا تعجز ===== //



signed main()
{
    fast;
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int dp[n+5];
    // dp[i] ==> at index i what is the minimum cost to get to the last index.

    // base case:
    dp[n-1] = 0;
    
    for(int i=n-2; i>=0; i--)
    {
        int mn = 1e9;
        for(int j=1; j<=k; j++)
        {
            if(j + i >= n)
                break;
            mn = min(dp[i+j] + abs(arr[i+j] - arr[i]), mn);
        }
        dp[i] = mn;
    }
    
    cout << dp[0] << endl;

}



