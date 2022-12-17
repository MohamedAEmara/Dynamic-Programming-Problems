
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;

/*
   استعن بالله ولا تعجز
*/


signed main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>odd;
        vector<int>even;
        int xor_odd=0, xor_even=0;
        for(int i=1; i<n; i+=2)
            odd.push_back(i), xor_odd ^= i;
        for(int i=2; i<n; i+=2)
            even.push_back(i), xor_even ^= i;
        for(auto it : odd)
            cout << it << " ";
        cout << endl;
        for(auto it : even)
            cout << it << " ";
        cout << endl;
        if(n & 1) // insert in an odd position
        {
            odd.push_back(xor_even ^ xor_odd);
        }
        else 
            even.push_back(xor_even ^ xor_odd);
    

        auto it_odd = odd.begin();
        auto it_even = even.begin();
        for(int i=0; i<n; i++)
        {
            if(it_odd != odd.end())
                cout << *it_odd << " ", it_odd ++;
            if(it_even != even.end())
                cout << *it_even << " ", it_even ++;
        } 
        cout << endl;
    }
    
}

