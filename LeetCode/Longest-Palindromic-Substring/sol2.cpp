class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int mx = 0;
        int best_start = 0, best_end = 0;
        for(int i=0; i<n; i++) {
            int l = i, r = i, len = 1;
            while(l > 0 && r < n-1) {
                l --, r ++;
                if(s[l] == s[r]) {
                    len += 2;
                    if(r - l + 1 > mx) {
                        best_start = l;
                        best_end = r;
                        mx = r - l + 1;
                    }
                } else {
                    // mx = max(len, mx);
                    break;
                }
            }
        }
        

        for(int i=0; i<n; i++) {
            int l = i, r = i-1, len = 0;
            while(l > 0 && r < n-1) {
                l --, r ++;
                if(s[l] == s[r]) {
                    len += 2;
                    if(r - l + 1 > mx) {
                        best_start = l;
                        best_end = r;
                        mx = r - l + 1;
                    }
                } else {
                    break;
                }
            }
        }

        string res = "";
        for(int i=best_start; i<=best_end; i++) {
            res += s[i];
        }
        return res;
    }

};