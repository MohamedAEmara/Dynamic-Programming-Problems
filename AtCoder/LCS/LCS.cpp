
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
 
/*
   استعن بالله ولا تعجز
*/
 
signed main()
{
   // fast;
    string a, b;
    int n, m;
    cin >> a >> b;
    n = a.length();
    m = b.length();

    int dp[n+2][m+2];
 
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    for(int i=0;i<=m;i++)
        dp[0][i] = 0;
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
 
 
    string ans = "";
 
    int i = n , j = m;
 
    while(i>0 && j>0)
    {
        if(dp[i-1][j] == dp[i][j])
            i --;
        else if(dp[i][j-1] == dp[i][j])
            j --;
        else 
        {
            ans += a[i-1];
            j--, i--; 
        }
    }
 
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
 
}

