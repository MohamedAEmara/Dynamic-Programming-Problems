class Solution {
public:
    int n;
    string s;

    // // We want to compute isPal[l][r];
    // // for every start (l) and end (r) we want to get the answer 
    // // isPalindrome??

    bool isPal[1005][1005];

    

    
string longestPalindrome(string str) {
    n = str.length();
    s = str;
    memset(isPal, 0, sizeof(isPal));

    for(int i=0; i<n; i++) {    // for every center
        int l = i, r = i;
        while(l >= 0 && r < n && l < n && r >= 0) {
            if(s[l] == s[r]) {
                isPal[l][r] = 1;
                l --, r ++;
            } else break;
        }
        l = i, r = i+1;
        while(l >= 0 && r < n) {
            if(s[l] == s[r]) {
                isPal[l][r] = 1;
                l --, r ++;
            } else break;
        }
    }

    // to find longest just loop over all substrings to find the longest
    int mx = 0;
    string res = "";

    for(int l=0; l<n; l++) {
        for(int r=l; r<n; r++) {
            if(isPal[l][r])
            {
                if((r-l+1) >= mx) {
                    mx = (r-l+1);
                    res = s.substr(l, (r-l+1));
                }
            }
        }
    }

    return res;
}

};