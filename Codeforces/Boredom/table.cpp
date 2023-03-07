
#include <bits/stdc++.h>
#define int long long
#define endl '\n';
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


// ====== استعن بالله ولا تعجز ===== //
signed main()
{
    fast;
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int mx = *max_element(arr, arr+n);
    int freq[mx+5];
    memset(freq, 0, sizeof(freq));
    for(int i=0; i<n; i++)
        freq[arr[i]] ++;
    int dp[mx+5];

    // base case ==> if I > mx --> dp = 0;
    dp[mx+1] = 0;
    dp[mx+2] = 0;
    for(int i=mx; i>0; i--)
    {
        // At every index ---> we max between taking it or leaving 
        // takeing means move 2 indices after with value of i * freq[i]
        // leaving means move to the next index
        dp[i] = max(dp[i+1], freq[i]*i + dp[i+2]);
    }

    cout << dp[1] << endl;
}

