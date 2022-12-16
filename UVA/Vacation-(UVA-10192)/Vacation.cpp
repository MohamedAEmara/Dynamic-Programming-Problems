#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/

string a, b;
int n, m;
int mem[105][105];

int LCS(int i, int j)
{
    // Base Case
    if(i>=n || j>=m)
        return 0;
    int &ret = mem[i][j];
    // Memoization
    if(~ret)
        return ret;

    // Transition:
    // if in the current i and j the caracters are the same
    // The best situation is to include both in our sequence
    if(a[i] == b[j])
        ret = 1 + LCS(i+1, j+1);
    // otherwise, I'll try  to skip the current character in the first string
    // or skip the current character in the second string
    else
    {
        int skip_first = LCS(i+1, j);
        int skip_second = LCS(i, j+1);
        ret = max(skip_first, skip_second);
    }

    return ret;
}

signed main()
{
    // -------------- IDEA --------------
    // We have to find the longest common subsequence
    int tc = 1;
    while(getline(cin, a))
    {
        if(a == "#")
            return 0;
        getline(cin, b);
        n = a.length();
        m = b.length();
        memset(mem, -1, sizeof mem);
        int mx = LCS(0, 0);
        cout << "Case #" << tc << ": you can visit at most " << mx << " cities." << endl;
        tc ++;
    }


}

