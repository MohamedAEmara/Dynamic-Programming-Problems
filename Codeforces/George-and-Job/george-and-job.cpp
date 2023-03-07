
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);  cin.tie(NULL);
using namespace std;
int mod = 1000000007;

/*
    استعن بالله ولا تعجر
*/

int n, m, k;
int arr[5005];
ll dp[5005][5005];

ll rec(int idx, int left)
{
    if(idx == n)
        return 0;
    if(left<=0)
        return 0;
    if(idx + m - 1 > n)
        return -1e9;
    ll &ret = dp[idx][left];
    if(ret != -1)
        return ret;
    ll sum = 0;
    for(int i=idx;i<idx+m;i++)
        sum += arr[i];
    ret = max(sum+rec(idx+m, left-1), rec(idx+1, left));
    return ret;
}




int main()
{
    fast;
    memset(dp, -1, sizeof dp);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout << rec(0, k) << endl;
}


