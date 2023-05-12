
class Solution {
public:
    int n;
    long long a[100005];
    long long b[100005];
    long long dp[100005][5];

    long long rec(long long idx, long long take)
    {
        if(idx >= n)
            return 0;
        long long &ret = dp[idx][take];
        if(~ret)
            return ret;
        
        return ret = max(a[idx]+rec(idx+b[idx]+1, 1), rec(idx+1, 0));
    }


    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        for(int i=0; i<n; i++)
        {
            a[i] = questions[i][0];
            b[i] = questions[i][1];
        }    
        memset(dp, -1, sizeof(dp));
        return rec(0, 0);
    }
};


