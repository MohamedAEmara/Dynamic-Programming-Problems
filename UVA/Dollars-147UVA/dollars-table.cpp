#include <bits/stdc++.h>
#define int long long
using namespace std;


// ======= استعن بالله ولا تعجز ====== //

const int COINS = 15;
const int MAX = 30005;
int coins[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
int n;
int dp[COINS][MAX];

int rec(int idx, int rem)
{
    if(rem == 0)
        return 1;

    if(rem < 0 || idx == 11)
        return 0;

    int &ret = dp[idx][rem];

    if(~ret)
        return ret;

                // Push Loop to Parameter //
    return ret = rec(idx+1, rem) + rec(idx, rem-coins[idx]);
    // leave it    --    or take one from current idx and stay at this idx.
}





signed main()
{
    double x;
    while(cin >> x)
    {   
        x *= 100;
        n = (int)x;
        if(n == 0)
            break;
        memset(dp, -1, sizeof(dp));
        int res = rec(0, n);
        cout << fixed << setprecision(2) << x/100.0 << setw(16) << res << endl;
          // First --> translate base case 
        //  if(rem == 0)
        //      return 1;
        // So, at all rem = 0      -->     dp[idx][rem] = 0

        // secondly, if(rem < coins[idx] or idx == 11)
        //      return 0;

        // lastly, translate this line.
        // ret = rec(idx+1, rem) + rec(idx, rem-coins[idx]);
        //  dp2[rem][idx] = dp2[rem][idx-1] + dp2[rem-coins[idx]][idx];
        
        int dp2[COINS][MAX];
        for(int i=0; i<COINS; i++)
            dp2[i][0] = 1;              // base case;


        int mx = 0;
        
        for(int rem = coins[0]; rem <= n; rem += 5)        // try all valid values for the input
        {
            cout << "outer" << " ";
            for(int j=1; j<COINS; j++)
            {
                cout << "inner" << endl;
                dp2[j][rem] = dp2[j-1][rem];               // first take the value of the same rem 
                                                           // but using other coins

                if(rem - coins[j] >= 0)                    // if I can take more from this index
                    dp2[j][rem] += abs(dp2[j][rem-coins[j]]);   // try to sty at the same index but with less rem
                                                           // "subtract the current coin from it"    
                mx = max(mx, dp2[j][rem]);
            }
        }

        cout << mx << endl;



        // for(int rem=0; rem<MAX; rem+=5)      // rem, +=5 ==> as stated in the problem (input % 5 = 0) 
        // {
        //     for(int idx=0; idx<COINS; idx++)        // idx
        //     {
        //         if(rem == 0)
        //             dp2[rem][idx] = 1;
        //         else if(rem < coins[idx] || idx == 11)
        //             dp2[rem][idx] = 0;
        //         else 
        //         {
        //             dp2[rem][idx] = dp2[rem][idx-1] + dp2[rem+coins[idx]][idx];
        //         }
        //     }
        // }

        for(int i=0; i<11; i++)
        {
            for(int j=0; j<30; j++)
            {
                cout << dp2[i][j] << " ";
            }
            cout << endl;
        }
    }



  
}