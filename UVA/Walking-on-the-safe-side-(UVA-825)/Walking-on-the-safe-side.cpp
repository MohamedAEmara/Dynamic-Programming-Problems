
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/

int n, m;

// use map for memoization and block locations
// As the statement doesn't contain any constrains.

set<pair<int,int>>block;
map<pair<int,int>,int>dp;

bool valid(int i, int j)
{
    return (i <= n && j <= m && block.find(make_pair(i, j)) == block.end());
}

int rec(int i, int j)
{
    if(i > n  j > m  i < 1  j < 1  block.find(make_pair(i, j)) != block.end())
        return 0;

    int &ret = dp[make_pair(i, j)];

    if(dp[(make_pair(i, j))])
        return ret;

    if(i == n && j == m)
        return 1;

    ret = 0;

    // Try to move right if valid
    if(valid(i, j+1))
        ret += rec(i, j+1);
    // Try to move down if valid
    if(valid(i+1, j))
        ret += rec(i+1, j);

    return ret;
}


signed main()
{
    int t;
    string tmp;
    getline(cin, tmp);
    t = stoll(tmp);
    while(t--)
    {
        // he mentioned that each test case contains an empty line
        string emptyLine;
        getline(cin, emptyLine);

        string tmp;
        getline(cin, tmp);
        string s;
        stringstream ss(tmp);

        n = -1;
        m = -1;
        while(ss >> s)
        {
            if(n == -1)
                n = stoll(s);
            else
                m = stoll(s);
        }

        for(int i=1; i<=n ; i++)
        {
            string line;
            getline(cin, line);

            stringstream ss(line);
            string s;
            int ok = 0;
            int x = 0;
            
            while(ss >> s)
            {
                if(x == 0)  // we're at the first number in the line
                    x = stoll(s);
                else
                    block.insert(make_pair(x, stoll(s)));
            }

        }

        cout << rec(1, 1) << endl;
        if(t > 0)  // if we are in the last test case --> don't print an empty line after the output
            cout << endl;

        dp.clear();
        block.clear();

    }
}



