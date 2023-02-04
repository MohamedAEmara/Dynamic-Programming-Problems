
11
3 2 2 1
4 5 5 2 2
3 6 7 8
4 2 3 4 5
2 24 12
2 1 1
12 1 2 3 4 5 6 7 8 9 10 11 12
4 2 3 4 19
5 3 4 2 1 11
3 10 20 30

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
int arr[105];
int sum_all = 0;
int dp[105][25005];  // note that no need to make the max_sum 500 * 100 but 250 * 100
                     // As We're not interested in values greater than half

int best = 1e9;
int rec(int idx, int summ)
{
    if(idx >= n || 2 * summ >= sum_all)
    {
        int tmp = (sum_all - 2 *summ);
        best = min(abs(tmp), best);
        return 0;
    }    
    int &ret = dp[idx][summ];
    if(~ret)
        return ret;
    int take = arr[idx] + rec(idx + 1, summ + arr[idx]);
    int leave = rec(idx + 1, summ);

    if(abs(sum_all - 2 * (summ + arr[idx])) <= abs(sum_all - 2 * summ))
    {
        int tmp = (summ + arr[idx]) * 2 - sum_all;
        best = min(abs(tmp), best);
        ret = take;
    }
    else
    {
        int tmp = (sum_all - 2 *summ);
        best = min(abs(tmp), best);
        ret = leave;
    } 
    // if the  sum exceeded the half value --> just leave the remaining elements

    return ret;
}

signed main()
{
    // ----------------------- IDEA --------------------------//
    // I want to separate the values into 2 groups at which the difference between the sum
    // of the first and the second be minimum.
    // First, We need to minimize the value of (half - group_sum)
    // So, the decision of leave or take is based on the min (half-take, half-take)
    fast;
    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;
        sum_all = 0;
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
            sum_all += arr[i];
        }

        // reset the dp array and best to minimiZe it
        memset(dp, -1, sizeof(dp));
        best = 1e9;
        rec(0, 0);
        cout << best << endl;
    }
}

