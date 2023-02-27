
#include <bits/stdc++.h>
#define ing long long
using namespace std;



int arr[55];
int n;
int dp[55][55];

int rec(int l, int r)
{
    if(r - l + 1 < 3)      // if length of segment less than 3 --> can't do anything
        return 0;
    
    if(r - l + 1 == 3)     // has just one option --> to bomb the middle
        return arr[l] * arr[r];
    
    int &ret = dp[l][r];
    if(~ret)
        return ret;
    
    ret = 0;
    // try to bomb any index between the two ends.
    // this results to split current segment into two groups
    // one from the left to the best index i ... and one from this best index to the right.
    for(int i=l+1; i<r; i++)
    {
        // if these two ends are tha last thing to bomb --> what is the best point to divide it 
        ret = max(ret, arr[l] * arr[r] + rec(l, i) + rec(i, r));   
    }

    return ret;
}


signed main()
{
    int tmp;
    vector<int>v;
    while(cin >> tmp)
    {
        v.push_back(tmp);
    }    
    n = v.size();
    for(int i=0; i<n; i++)
        arr[i] = v[i];
    
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n-1) << endl;
    
}


