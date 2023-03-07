
#include <bits/stdc++.h>
#define int long long
#define endl '\n';
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


// ====== استعن بالله ولا تعجز ===== //

int n;
int mx;
const int N = 1e5 + 5;
const int MAX = 1e5 + 5;
int arr[N];
int freq[MAX];
int dp[MAX];


int rec(int last)
{
    if(last > mx)   
        return 0;
    int &ret = dp[last];
    if(~ret)
        return ret;

    // At every index ---> if I take this index --> add the freq * val of that index 
    // and we can't take the next index to it === > so the transition will be last  + 2
    // If we skip this index and don't take it ==> just move to the next "last + 1"
    return ret = max(last * freq[last] + rec(last + 2) , rec(last + 1));
}

signed main()
{
    fast;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    memset(freq, 0, sizeof(freq));
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++)
        freq[arr[i]] ++;
    mx = *max_element(arr, arr+n);
    cout << rec(1) << endl;
}

