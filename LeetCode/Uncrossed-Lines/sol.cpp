
class Solution {
public:
    int a[505], b[505];
    int n, m;
    int dp[505][505];

    int rec(int i, int j)
    {
        if(i >= n || j >= m)
            return 0;
        int &ret = dp[i][j];
        if(~ret)
            return ret;

        if(a[i] == b[j])    // best is to take
            return ret = 1 + rec(i+1, j+1);
        else
            return ret = max(rec(i+1, j), rec(i, j+1));
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // longest common subsequence 
        n = nums1.size();
        m = nums2.size();
        for(int i=0; i<n; i++)
            a[i] = nums1[i];
        for(int i=0; i<m; i++)
            b[i] = nums2[i];
       
        memset(dp, -1, sizeof(dp));

        return rec(0, 0);
    }
};

