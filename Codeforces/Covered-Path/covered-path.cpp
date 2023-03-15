
#include <bits/stdc++.h>
#define int long long
using namespace std;

int v1, v2, t, d;
int dp[105][1105];      // 1105 to consider the max val I can get 100 * 10 + 100

int rec(int idx, int val) 
{
    // cout << idx << " -> " << val << endl;
    if(idx == t) 
    {
        if(val != v2)
            return -1e15;           // if ended with any other value --> drop this solution
        else return 0;    
    }

    int &ret = dp[idx][val];
    if(~ret)    
        return ret;
    
    ret = val + rec(idx+1, val);        // no change in speed

    for(int i=1; i<=d; i++)             // change the speed +ve or -ve
    {
        ret = max(ret, val+i + rec(idx+1, val+i));
        if(val - i >= 0)
            ret = max(ret, val-i + rec(idx+1, val-i));
    }
    return ret;
}

signed  main()
{
    cin >> v1 >> v2 >> t >> d;
    memset(dp, -1, sizeof(dp));
    cout << v1 + rec(1, v1) << endl;        // add v1 to the res as we always have v1 in our 
                                            // calculations but didn't include it in the rec function.
}



