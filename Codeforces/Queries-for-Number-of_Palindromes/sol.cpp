
#include <bits/stdc++.h>
//#define int long long
#define fast cin.tie(0); cin.sync_with_stdio(0);
#define endl '\n';
using namespace std;


// ====== استعن بالله ولا تعجز ===== //


string s;
const int N = 5005;
bool isPalindrome[N][N];
bool vis1[N][N];
int cntPalindrome[N][N];
bool vis2[N][N];

// find every substrings is palindrome or not.
bool rec1(int i, int j)
{
    if(i == j)
        return 1;

    if(i > j)
        return 1;

    if(vis1[i][j])
       return isPalindrome[i][j];
    vis1[i][j] = 1;
    return isPalindrome[i][j] = ((s[i] == s[j]) && rec1(i+1, j-1));
}


// how many palindrome substrings are there in range i, j?

int rec2(int i, int j)
{
    if(i > j)
        return 0;

    if(vis2[i][j])
        return cntPalindrome[i][j];

    vis2[i][j] = 1;
    return cntPalindrome[i][j] = rec1(i, j) + rec2(i, j-1) + rec2(i+1, j) - rec2(i+1, j-1);

}

signed main()
{

    fast;

    cin >> s;

    int q; cin >> q;
    while(q --)
    {
        int l, r;
        cin >> l >> r;
        cout << rec2(l-1, r-1) << endl;
    }


}

// Note that this solution will TLE without fast I/O && '\n' rather than endl

