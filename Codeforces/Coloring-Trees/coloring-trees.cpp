


#include <bits/stdc++.h>
#define int long long
#define ll long long
#define MohamedEmara ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/

ll n, m, k;
const ll MAX = 105;
ll color[MAX];
ll matrix[MAX][MAX];
ll dp[MAX][MAX][MAX];
ll mn = 1e15;


int rec(int idx, int prev, int len)
{
    if(idx == n)
    {
        if(len == k){
            return 0;
        }
        else 
            return 1e15;
    }

    int &ret = dp[idx][prev][len];
    if(~ret)
        return ret;

    if(color[idx] == 0)
    {
        int tmp = 1e15;
        for(int i=0; i<m; i++)
        {
            tmp = min(tmp, matrix[idx][i] + rec(idx+1, i+1, len + (idx==0 or i+1!=prev)));
        }
        ret = tmp;
    }
    else 
    {
        ret = rec (idx+1, color[idx], len + (idx == 0 or prev != color[idx]));
    }
    
    return ret;
}




signed main()
{
    MohamedEmara;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        cin >> color[i];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    mn = rec(0, 0, 0);

    if(mn == 1e15)  
        cout << -1 << endl;
    else 
        cout << mn << endl;

    
}




