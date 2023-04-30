
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;


int n;
int arr[5005];
int dp[5005][5005];
int MX[5005][5005];

// First, We create a 2D array to calculate every f(a, b)
// starting from every position in arr & end with every valid end
int rec(int a, int b)
{
    if(a == b)
        return arr[a];
    if(a > b)
        return 0;
    int &ret = dp[a][b];
    if(~ret)
        return ret;
    return ret = (rec(a+1, b) ^ rec(a, b-1));
}

int mx(int a, int b)
{
    if(a == b)
        return arr[a];
    if(a > b)
        return 0;
    int &ret = MX[a][b];
    if(~ret)
        return ret;
    return ret = max({rec(a, b), mx(a+1, b), mx(a, b-1)});
    // we have 3 options
    /*
        1 - max is the segment itself from a to b               (rec(a, b))
        2 - max is a subsegment by moving from the right side   (mx(a+1, b))
        3 - max is a subsegment by moving from the left side    (mx(a, b-1))
    */
}



signed main()
{
    fast;

    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    
    memset(dp, -1, sizeof(dp));
    memset(MX, -1, sizeof(MX));

    int q;
    cin >> q;
    while(q --)
    {
        int l, r;
        cin >> l >> r;
        l --, r --;
        cout << mx(l, r) << endl;
    }
}


