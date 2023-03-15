
#include <bits/stdc++.h>
#define int long long
using namespace std;


int n;
const int N = 2005;
int arr[N];
int dp[N][N];

int rec(int l, int r)
{
    if(l == r)
        return arr[l] * (n-(r-l));     


    int &ret = dp[l][r];
    if(~ret)
        return ret;
    
     // multiply the value of the taken index by the turn  ---> turn = (n-(r-l)) 
    return ret = max(arr[l] * (n-(r-l)) + rec(l+1, r), arr[r] * (n-(r-l)) + rec(l, r-1));
}

signed main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n-1) << endl;
}


