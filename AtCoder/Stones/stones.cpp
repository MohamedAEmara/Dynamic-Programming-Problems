
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


// ====== استعن بالله ولا تعجز ===== //


signed main()
{
    fast;
    int n, k;
    cin >> n >> k;
    int pile[n+5];
    for(int i=0; i<n; i++)
        cin >> pile[i];

    bool dp[k+5];
    // Firstly, assign all values to False;
    memset(dp, false, sizeof(dp));
    // dp[i] is true if the player who will play wins, false otherwise
    // all values smaller than the minimum element in the array will remain false

    for(int rem=0; rem<=k; rem++)
    {
        bool mx = false;
        for(int i=0; i<n; ++i)
        {
            if(rem >= pile[i] /*&& rem - pile[i] < mn*/)
                mx = max(mx, !dp[rem - pile[i]]);
        }
        dp[rem] = mx;

    }
    if(dp[k])
        cout << "First" << endl;
    else
        cout << "Second" << endl;

}




