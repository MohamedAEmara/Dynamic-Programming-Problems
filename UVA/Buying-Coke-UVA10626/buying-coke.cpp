
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define MohamedEmara ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
    استعن بالله ولا تعجز
*/

int n, one, five, ten;
int dp[720][160][60];

int rec(int rem, int rem_ones, int rem_fives, int rem_tens)  // remaining cola needed , one , five , ten
{
    // Invalid case:
    if(rem_ones < 0 or rem_fives < 0 or rem_tens < 0)
        return 1e15;  // return a max value to be ignored when minimizing.
    
    // Base case
    if(rem == 0)
        return 0;
    
    int &ret = dp[rem_ones][rem_fives][rem_tens];
    if(~ret)
        return ret;
        
    int use_ten                          = 1 + rec(rem-1, rem_ones+2, rem_fives, rem_tens - 1);
    int use_five_and_three_ones          = 4 + rec(rem-1, rem_ones-3, rem_fives-1, rem_tens);
    int use_eight_ones                   = 8 + rec(rem-1, rem_ones - 8, rem_fives, rem_tens);
    int use_two_fives                    = 2 + rec(rem-1, rem_ones+2, rem_fives-2, rem_tens);
    int use_ten_and_three_ones           = 4 + rec(rem-1, rem_ones-3, rem_fives+1, rem_tens-1);
    int use_ten_and_five_and_three_ones  = 5 + rec(rem-1, rem_ones-3, rem_fives-1, rem_tens);

    ret = min({use_ten, use_five_and_three_ones, use_eight_ones, use_two_fives, use_ten_and_three_ones, use_ten_and_five_and_three_ones});

    return ret;
}
signed main()
{
    MohamedEmara;
    int t; cin >> t;

    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> n >> one >> five >> ten;
        cout << rec(n, one, five, ten) << endl;
    }
}



