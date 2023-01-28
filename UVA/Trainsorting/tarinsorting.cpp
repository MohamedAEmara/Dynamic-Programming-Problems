#include <bits/stdc++.h>
#define ll long long
#define MohamedEmara ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/



int n;
int arr[2005];

int LIS[2005];
int LDS[2005];



signed main()
{

    /* ================ IDEA =============*/
    /*
        At each position, we will see what will be the cost of 
        LIC and LDS 
        I start calculating LIS and LDS from that position

        Maximize the sum of LIS and LDS at each position

                    1  4  5  3  2

    LIS           :       3  2  1  1  1 
    LCS           :       1  3  3  2  1
    LIS + LDS - 1 :       3  4  3  2  1

    */
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> arr[i];


        LIS[n] = 1;
        for(int i=n-1; i>=1; i--)
        {
            int mx = 1;
            for(int j=i; j<=n; j++)
            {
                if(arr[j] > arr[i]){
                    mx = max(mx, 1+LIS[j]);
                }
            }
            LIS[i] = mx;
        }

        LDS[n] = 1;
        for(int i=n-1; i>=1; i--)
        {
            int mx = 1;
            for(int j=i; j<=n; j++)
            {
                if(arr[j] < arr[i]){
                    mx = max(mx, 1+LDS[j]);
                }
            }
            LDS[i] = mx;
        }

        int res = 0;
        for(int i=1; i<=n; i++){
            res = max(res, LIS[i]+LDS[i]-1);
        }

        cout << res << endl;        

    }
}




