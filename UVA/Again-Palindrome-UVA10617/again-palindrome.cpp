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
int n;
int dp[65][65];

int rec(int i, int j)
{
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    if(i == j)
        return 1;
    if(i+1 == j)
    {
        if(s[i] == s[j])
            return 3;  // aa  --> {a, a, aa}
        else
            return 2;  // ab  --> {a, b}
    }

    ret = 0;

    if(s[i] == s[j])
        ret = 1 + rec(i+1, j-1);

    ret += rec(i+1, j);
    ret += rec(i, j-1);
    ret -= rec(i+1, j-1);  // Remove duplication of the previous two transitions.

    return ret;
}


signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        n = s.length();
        memset(dp, -1, sizeof (dp));
        cout << rec(0, n-1) << endl;
    }
}
