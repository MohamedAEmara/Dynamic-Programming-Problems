class Solution {
public:
    long long dp[55][55];
   
    long long rec2(int rem, int cnt) {
        if(rem == 0) {
            if(cnt == 1) {
                return -1e9;
            }
            return 1;
        }

        long long &ret = dp[rem][cnt];
        if(~ret) return ret;

        for(int i=1; i<=rem; i++) {
            ret = max(ret, i * rec2(rem-i, cnt+1));
        }

        return ret;
    }



    
    long long integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        return rec2(n, 0);
    }
};