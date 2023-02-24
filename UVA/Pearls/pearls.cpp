
#include <bits/stdc++.h>
using namespace std;


const int N = 105;
int memo[N][N];
int cnt[N];
int cost[N];
int n;

int best(int currIdx, int startGroupIdx)
{
    // base case:
    if(currIdx == n)
        return 0;

    // state ---> currIdx, lastIdx
    int &ret = memo[currIdx][startGroupIdx];
    if(~ret)
        return ret;

    // for every idx --> if I'll take it add 10 first
    // then see How many items will I take if I end this category at this index.
    int sum = 10;
    for(int i=startGroupIdx; i<=currIdx; i++)
    {
        sum += cnt[i];
    }

    // this sum will be multiplied by the cost --> if take this index
    // an end of a group
    ret = best(currIdx+1, currIdx+1) + sum * cost[currIdx];


    // the last index (n-1) has no other choice than to be an end of a group
    if(currIdx != n-1)
        ret = min(ret, best(currIdx + 1, startGroupIdx));

    return ret;

}
signed main()
{
    int t; cin >> t;
    while(t --)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> cnt[i] >> cost[i];
        }
        memset(memo, -1, sizeof(memo));
        cout << best(0, 0);
    }
}


