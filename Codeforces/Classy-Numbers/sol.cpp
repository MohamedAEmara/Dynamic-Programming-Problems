
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

int a, b;
string s;
int len;
int dp[20][5][5];


// start by can = 0 .. as the first digit can go only up to it's original digit
// at each step, if the curr idx is not the original --> so the comming digits can 
// go from 0 to 9 
// but if the curr idx is the max (equals it's original) --> the next digit is bounded by
// its original value


int rec(int idx, int cnt, bool can)
{
    if(cnt > 3)         // can't continue if the curr non-zero digits is > 3
        return 0;
    
    if(idx == len)      // if we reached the end of the string without any breaks 
        return 1;       // so, it's a valid solution... add 1 to count them all 
    
    int &ret = dp[idx][cnt][can];

    if(~ret)
        return ret;
    
    int mx = s[idx] - '0';

    if(can)
    {
        mx = 9;
    }

    ret = 0;

    // all digits till mx-1 ---> can = 1 , As I can use any digit after 
    for(int i=0; i<mx; i++)
    {
        ret += rec(idx+1, cnt+(bool)(i), 1);
    }

    // but if the curr is the original.. I'm bounded by the original digit in the next idx
    ret += rec(idx+1, cnt+(bool)(mx), can);

    return ret;
}

int solve(int n)
{
    // Reset global variables for a new number
    s = to_string(n);
    len = s.length();
    memset(dp, -1, sizeof(dp));


    return rec(0, 0, 0);
    // this value is all classy numbers between 0 & n
    // if we calculate classy numbers for a, then for b
    // subtract them to get the inclusive classy numbers.
}


signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;

        int to_a_minus_one = solve(a-1);    // minus one to include the number a
        int to_b = solve(b);                // if it's a classy number.
        cout << to_b - to_a_minus_one << endl;
    }
}

