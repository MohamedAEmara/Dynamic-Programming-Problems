
#include <bits/stdc++.h>
#define int long long
#define MohamedEmara ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

// ===== استعن بالله ولا تعجز ===== //

const int N = 3005, M = 3005;
string a, b;
int n, m;
int mx;

string res = "";

int dp[N][M];

int rec(int i, int j)
{
    if(i == n || j == m)
        return 0;
    
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    
    if(a[i] == b[j])
        ret = 1 + rec(i+1, j+1);
    else 
        ret = fmax(rec(i+1, j), rec(i, j+1));
    
    return ret;
}


void build(int i, int j)
{   
    if(i == n || j == m)
        return;
    int ret = rec(i, j);
    if(a[i] == b[j])
    {
        res += a[i];
        build(i+1, j+1);
    }
    else
    {
        if(rec(i+1, j) >= rec(i, j+1))
            build(i+1, j);
        else 
            build(i, j+1);
    }
}

signed main()
{
    MohamedEmara;
    cin >> a >> b;
    n = a.length();
    m = b.length();
    memset(dp, -1, sizeof(dp));

    mx = rec(0, 0);
   
    build(0, 0);

    cout << res << endl;

}

