
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
const int N = 3005;
int arr[N];
int dp[N][N];

int rec(int l, int r) 
{
    if(l == r)
        return arr[l];
    int &ret = dp[l][r];
    if(~ret)
        return ret;
    return ret = max(arr[l] - rec(l+1, r), arr[r] - rec(l, r-1));
    // arr[l] - rec(l+1, r) ===> this means add the current idx
    // when we calculate the rec(l+1, r) the next choice will be with -ve sign
    // the turn after the next turn will be +ve sign ==> -v(-v) -> "+ve"

}

signed main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n-1) << endl;
}


