

#include <bits/stdc++.h>
#define int long long
using namespace std;


/// ======  استعن بالله ولا تعجز  ====== ///

const int N = 5005;
int n, k;
int arr[N];
int dp[N][N];

int rec(int idx, int rem)
{
    if(idx == n)
        return 0;
    int &ret = dp[idx][rem];
    if(~ret)
        return ret;
    ret = rec(idx+1, rem);
    if(rem)     // see how many indices I cant take with the total diff <= 5
    {
        int first = arr[idx];
        int mx = arr[idx] + 5;
        int last = idx;
        for(int i=idx+1; i<n; i++)
        {
            if(arr[i] <= mx)
                last = i;
            else 
                break;
        }
        ret = max(ret, last - idx + 1 + rec(last + 1, rem-1));      // last + 1     
    }                                                               // not to include last twice :)
    return ret;
}

signed main()
{
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    memset(dp, -1, sizeof(dp));
    cout << rec(0, k) << endl;
}


