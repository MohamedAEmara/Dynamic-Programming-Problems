
#include <bits/stdc++.h>
#define int long long
#define MohamedEmara ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/


// to find lis in nlog(n)
vector<int>LIS(vector<int>&v)
{
    int n = v.size();
    vector<int>res;
    vector<int>groups;
    for(int i=0; i<n; i++)
    {
        auto idx = lower_bound(groups.begin(), groups.end(), v[i]) - groups.begin();
        if(idx == groups.size())
            groups.push_back(v[i]);
        else groups[idx] = v[i];
        res.push_back(groups.size());
    }

    return res;
}


signed main()
{
    MohamedEmara;
    int n;
    while(cin >> n)
    {
        vector<int>arr(n);
        vector<int>reversed(n);

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
            reversed[i] = arr[i];
        }

        reverse(reversed.begin(), reversed.end());

        vector<int>lisRight(n);
        vector<int>lisLeft(n);

        lisLeft = LIS(arr);
        lisRight = LIS(reversed);

        int res = 1;
        for(int i=0; i<n; i++)
        {
            if(lisLeft[i] == lisRight[n-i-1])
                res = max(res, (lisLeft[i] + lisRight[n-i-1]) - 1);
        }

        cout << res << endl;


    }
}

