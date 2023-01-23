#include <bits/stdc++.h>
#define int long long
#define MohamedEmara ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/

int n;
string s[100005];
int cost[100005];
int dp[100005][3];           // index , reverse it or not
                             // zero for not reverse , one for reverse , two for the first call

int rec(int idx, int rev, string last)
{
    string tmp = s[idx];
    reverse(tmp.begin(), tmp.end());
    
   
    if(idx >= n){
     //   cout << "Base case" << endl;
        return 0;
    }

    if(last > s[idx] && last > tmp){
      //  cout << "Invalid case" << endl;
        return 1e15;  // make the value maximum to be excluded from options ... or there is no solution
    }


    int &ret = dp[idx][rev];
    if(~ret){
      //  cout << "Memoized" << endl;
        return ret;
    }    
    else if(last > s[idx] && last <= tmp)
    {
      //  cout << "Better to take the reversed string" << endl;
        ret = cost[idx] + rec(idx+1, 1, tmp);
    }
    else if(last <= s[idx] && last <= tmp)
    {
      //  cout << "Both are good ---> Take the minimum path" << endl;
        ret = min(cost[idx] + rec(idx+1, 1, tmp) , rec(idx+1, 0, s[idx]));
    }
    else if(last <= s[idx] && last > tmp)
    {
      //  cout << "Better to take the original string" << endl;
        ret = rec(idx+1, 0, s[idx]);
    }

    return ret;


}

signed main()
{

    // ------------------- IDEA ---------------- //
    // at every string ---> we check if reversed(s[idx]) <= previous && s[idx] <= previous --->
    // so, I have the option to keep it or reverse it --> take the minimum of them

    // if only the reversed string is lexicographically greater than the previous --> just reverse it and 
    // add the cost of that reverse to the total sum

    // if only the original string (s[idx]) is lexicographically greater than the previous --> do nothing to this index

    // As the first element has no preivous --> we have to initialize last with "" empty string --> any other string is lexico greater

    // If there is no solution ---> the result of the recursive call will be >= 1e15 (Invalid case)

    MohamedEmara;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> cost[i];
    for(int i=0; i<n; i++)
        cin >> s[i];

    memset(dp, -1, sizeof(dp));
    
    int res = rec(0, 2, "");
    if(res >= 1e15)
        cout << -1 << endl;
    else 
        cout << res << endl;

}
