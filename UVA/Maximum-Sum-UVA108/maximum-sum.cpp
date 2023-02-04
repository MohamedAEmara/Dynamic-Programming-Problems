#include <bits/stdc++.h>
#define int long long
#define MohamedEmara ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define ll long long
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/


int arr[105][105];
int max_sum = -1e15;



void maxSubArray(vector<int>tmp, int n)
{
    int sofar = 0;
    int it = 1;

    while(tmp[it] <= 0 && it < n)
        it ++;

    int tmp_mx = 0;
    while(it <= n)
    {
        if(tmp[it] + sofar > 0)
            sofar += tmp[it];
        else
            sofar = 0;

        tmp_mx = max(tmp_mx, sofar);
        it ++;
    }

    if(tmp_mx > max_sum)
        max_sum = tmp_mx;

}


signed main()
{
    MohamedEmara;
    int n;
    cin >> n;

    /*================  IDEA  =================*/
    /*
        We have to try all lefts with all rights and for each segment between
        we calculate the max subArray of the prefix from left to right 
    */
    
    

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> arr[i][j];
        }
    }

    

    for(int l=1; l<=n; l++)
    {
        vector<int>tmp(n+5);
        for(int i=1; i<=n; i++)
            tmp[i] = arr[i][l];

        maxSubArray(tmp, n);

        int sofar = 0;
        int it = 1;

        for(int r=l+1; r<=n; r++)
        {
            for(int i=1; i<=n; i++)
                tmp[i] += arr[i][r];

            maxSubArray(tmp, n);
        }

    }

    cout << max_sum << endl;
}
