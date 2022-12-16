#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/

int n, m;
char arr[1005][1005];
int mem[1005][1005];

bool valid(int i, int j)
{
    if(i<n and j<m and arr[i][j] == '.')
        return 1;
    return 0;
}

int rec(int i, int j)
{
    int &ret = mem[i][j];
    if(ret != -1)
        return ret;
    if(i >= n || j >= m || arr[i][j] == '#')
        return (ret = 0);
    if(i == n-1 && j == m-1)
        return (ret = 1);
    
    int down = (rec(i+1, j)) % mod;
    int right = (rec(i, j+1)) % mod;

    ret = 0;
    if(valid(i+1, j))
        ret += down;
    if(valid(i, j+1))
        ret += right;
    ret %= mod;
    return ret;
}

signed main()
{
    fast;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    memset(mem, -1, sizeof(mem));
    int res = rec(0, 0);
    res %= mod;
    cout << res << endl; 
}

