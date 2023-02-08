
#include <bits/stdc++.h>
#define int long long
#define MohamedEmara ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/
int n;
int flow[25];
int cost[25];
int vol[25];
map<pair<int,int>,int>dp;

int rec(int idx, int rem)
{
    if(idx == n){
        if(rem > 0)
            return 1e18;
        else return 0;
    }

    if(dp.count(make_pair(idx, rem)))
       return dp[make_pair(idx, rem)];

    int leave = rec(idx+1, rem);
    int take = cost[idx] + rec(idx+1, rem-vol[idx]);

    return dp[make_pair(idx, rem)] = min(leave, take);
}


signed main()
{
    MohamedEmara;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> flow[i] >> cost[i];

    int t; cin >> t;
    for(int tt=1; tt<=t; tt++)
    {
        int volume, hours;
        cin >> volume >> hours;
        for(int i=0; i<n; i++)
            vol[i] = hours * flow[i];
        dp.clear();
        int res = rec(0, volume);
        cout << "Case " << tt << ": ";
        if(res == 1e18)
            cout << "IMPOSSIBLE" << endl;
        else cout << res << endl;
    }
}


