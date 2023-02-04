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
int v[1005];
int w[1005];
int g;
int person[105];
const int MX_weight = 35;
const int MX_object = 1005;
int mem[MX_object][MX_weight];

int rec(int idx, int rem)
{
    if(rem <= 0 || idx >= n)
        return 0;
    int &ret = mem[idx][rem];
    if(~ret)
        return ret;
    // If I can't take this item ---> just leave it
    if(rem < w[idx])
        ret = rec(idx+1, rem);
    // otherwise ---> choose the max between taking it or leaving
    else
    {
        int leave = rec(idx+1, rem);
        int take = v[idx] + rec(idx+1, rem-w[idx]);
        ret = max(leave, take);
    }
    return ret;

}


signed main()
{
    // -------------- IDEA --------------
    // In each test case, We will find the max_value_product everyone can take from the store
    // considering that no one can take more than one item from each object
    int t;
    cin >> t;
    while(t --)

    {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> v[i] >> w[i];
        cin >> g;
        for(int i=0; i<g; i++)
            cin >> person[i];
        int val = 0;
        for(int i=0; i<g; i++)
        {
            // Reset the memoization array after every person buy his products
            memset(mem, -1, sizeof (mem));
            val += rec(0, person[i]);
        }
        cout << val << endl;
    }

}

