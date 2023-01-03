
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/

int n, m, x, y;
char grid[1110][1110];
int black[1110];
int white[1110];
int dp[1110][1110][5];  // number of columns, number of consecutive columns, current is black or white

int rec(int col, int black_width=0, int white_width=0)
{
    if(white_width > y  black_width > y)
        return 1e15;
    if(col == m)
    {
        if((black_width >= x && black_width <= y)    (white_width >= x && white_width <= y)) // the last segment taken is valid??
            return 0;
        else
            return 1e15;    // spoil the value to be excluded when minimizing
    }
    int current_color = 0;
    if(black_width > white_width)
        current_color = 1;
    else if(black_width < white_width)
        current_color = 2;
    int &ret = dp[col][max(black_width, white_width)][current_color];
    if(~ret)
        return ret;

    int make_white = black[col] + rec(col+1, 0, white_width+1);
    int make_black = white[col] + rec(col+1, black_width+1, 0);

    ret = 1e18;

    // Can I make this column black ???
    if(black_width < y && ((white_width >= x && white_width <= y)  (white_width == 0)))  // previous white is ok or is zero
        ret = min(ret, make_black);
    if(white_width < y && ((black_width >= x && black_width <= y)  (black_width == 0)))
        ret = min(ret, make_white);

    return ret;
}


signed main()
{
    cin >> n >> m >> x >> y;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];

    memset(dp, -1, sizeof(dp));
    for(int j=0; j<m; j++)
    {
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(grid[i][j] == '#')
                cnt++;
        }
        black[j] = cnt;
        white[j] = n - cnt;
    }

    cout << rec(0) << endl;

}



