#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/

int n;
double arr[3005];
double mem[3005][3005];

double rec(int idx, int cnt_heads)
{
    double &ret = mem[idx][cnt_heads];
    if(ret != -1.0) return ret;
    if(idx == n+1)
        return (ret = 0);
    if(idx == n)
    {
        if(cnt_heads > n - cnt_heads)
            return (ret = 1); 
        else 
            return (ret = 0); 
    }
    double head = arr[idx] * rec(idx+1, cnt_heads + 1);
    double tail = (1.0 - arr[idx]) * (rec(idx+1, cnt_heads));
    return (ret = (tail + head));
}

signed main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    for(int i=0; i<3005; i++)
        for(int j=0; j<3005; j++)  
            mem[i][j] = -1.0;
    double ans = rec(0, 0);
    cout << fixed << setprecision(10) << ans << endl;
}

