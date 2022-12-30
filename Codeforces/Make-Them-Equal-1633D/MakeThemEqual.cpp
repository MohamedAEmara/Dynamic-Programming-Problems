
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/

const int MAX_N = 1005;
const int MAX_OPERATIONS = 12 * 1005;
int cost[MAX_N + 5];
int b[MAX_N + 5], c[MAX_N + 5];
int n, k;
int dp[MAX_N + 5][MAX_OPERATIONS + 5];


int rec(int idx, int rem)
{
    if(idx == n) // if rem == 0 don't "return 0" as maybe some coins with zerooooooo const
        return 0;
    int &ret = dp[idx][rem];
    if(~ret)
        return ret;
    if(rem >= b[idx])
        ret = max(c[idx] + rec(idx+1, rem-b[idx]), rec(idx+1, rem));
    else
        ret = rec(idx+1, rem);

    return ret;
}


signed main()
{

    // ---------------------------- IDEA ------------------------ //
    /*  1- Calculate the minimum number of operations to get the number from number '1'
        2- As the numbers are up to 1000 --> it's better to prepare them in an array (cost)
        3- After getting the  needed number of operation for every number --> apply leave or take dp to
           find the optimal way to get the max number of coins
    */

    fast;

    for(int i=0; i<1005; i++)
        cost[i] = 10000;

    cost[0] = 0, cost[1] = 0;

    for(int i=1; i<1005 ; i++)
    {
        for(int j=1; j<=i; j++)
        {
            int tmp = i + i/j;
            if(tmp >= 1005)
                continue;
            cost[tmp] = min(cost[tmp], cost[i] + 1);
        }
    }

    // int mx_cost = *max_element(cost, cost + 1005);

    // Although K is so big ---> We are not interested in its max value as the max cost of operations
    // on any number is 12 "From experimenting the array"
    // ---> So when k >= 12 * n "this means I can take all the elements;
    // The size of dp[max_n][max_operation]  --> dp[1005][12*1005]

    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;

        // In order not to cause overflow --> When k is greater than MAX_OPERATIONS
        // Set it to MAX_OPERATIONS
        if(k >= MAX_OPERATIONS)
            k = MAX_OPERATIONS;

        for(int i=0; i<n; i++)
            cin >> b[i];
        for(int i=0; i<n; i++)
            cin >> c[i];
        for(int i=0; i<n; i++)
            b[i] = cost[b[i]];

        memset(dp, -1, sizeof(dp));
        cout << rec(0, k) << endl;
    }
}


