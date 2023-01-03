
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/

string s;
int dp[1110][1110];

int rec(int i, int j)
{
    if(i >= j)
        return 0;
    int &ret = dp[i][j];

    if(~ret)
        return ret;

    if(s[i] == s[j])
    {
        ret = rec(i+1, j-1);
    }
    else
    {
        ret = min({1 + rec(i+1, j), 1 + rec(i, j-1), 1 + rec(i+1, j-1)});
    }

    return ret;

}

signed main()
{
    fast;
    int t;
    cin >> t;
    for(int tt=1; tt<=t; tt++)
    {
        cin >> s;
        memset(dp, -1, sizeof(dp));
        cout << "Case " << tt << ": " << rec(0, s.length()-1) << endl;
    }

}



