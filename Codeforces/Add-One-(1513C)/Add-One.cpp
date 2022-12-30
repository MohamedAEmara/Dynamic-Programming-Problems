#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/

int m;
int dp[10][200005];

int rec(int i, int rem)
{
    if(rem <= 0)
        return 1;
    int &ret = dp[i][rem];

    if(~ret)
        return ret;

    int tmp = 10 - i;

    if(rem < tmp)
        return ret = 1;

    ret = (rec(1, rem - tmp)%mod + rec(0, rem - tmp)%mod)%mod;

    return  ret;
}

signed main()
{

    // ---------------- IDEA ----------------- // 
    // Every digit in the number is separated, for example 104 is same result as 410 
    // and the length after 'x' operations on digit 'i' if the x + i <= 9
    // after number of operations on digit i equal (10-i) number becomes 10 ---> So, We have 2 new numbers one is '0' other is '1'
    
    fast;
    int t;
    cin >> t;
    
    
    // No need to reinitialize it every test case --> results are the same for the same digit with
    // the same number of operations

    memset(dp, -1, sizeof(dp));

    while(t--)
    {
        string s;
        cin >> s >> m;
        int len = s.length();
        int res = 0;

        for(int i=0; i<len; i++)
        {
            res += rec(s[i]-'0', m) % mod;
            res %= mod;
        }
        cout << res << endl;
    }

}


