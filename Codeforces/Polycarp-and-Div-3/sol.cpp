
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

// ============== استعن بالله ولا تعجز ============== // 


int n;
const int MAX = 200005;
int dp[MAX][5];
int arr[MAX];

int rec(int idx, int sum)
{
    if(idx == n)
        return 0;
    int &ret = dp[idx][sum];
    
    if(~ret)
        return ret;

    // can I end at this point?
    if((arr[idx]+sum) % 3 == 0)
    {
        // maximize between 
        // include this point as the end of this segment
        //      in this case increment the res by 1 & reinitialize sum
        // OR
        // include this point as a start of a new segment
        //      in this case the sum will be the same & won't increment the ans
        
        ret = max(1 + rec(idx+1, 0), rec(idx+1, sum));
    }
    else 
    {
        ret = max(rec(idx+1, 0), rec(idx+1, (sum+arr[idx])%3));
    }
    return ret;
}

signed main()
{
    string s;
    cin >> s;
    n = s.length();
    memset(dp, -1, sizeof(dp));
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<n; i++)
    {
        arr[i] = (s[i] - '0');
    }
    cout << rec(0, 0) << endl;
}


