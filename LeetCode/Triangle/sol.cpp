
class Solution {
public:
    int n, m;
    int grid[205][500];
    int dp[205][500];

    bool valid(int i, int j) {
        return (i < n && j < m && j >= 0);
    }
    int rec(int i, int j) {
    if(i == n-1)
        return grid[i][j];

    int &ret = dp[i][j];
    if(~ret)
        return ret;
    int left = 1e9;
    if(valid(i+1, j-1))
        left = grid[i][j] + rec(i+1, j-1);
    int right = 1e9;
    if(valid(i+1, j+1))
        right = grid[i][j] + rec(i+1, j+1);
    return ret = min(left, right);
}

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        m = 2*(n-1) + 1;
        for(int i=0; i<n; i++) {
            vector<int>v;
            v = triangle[i];
            int it = 0;
            int start = (n-1) - i;

            for(int j=start; j<m && cnt<=i; j+=2) {
                grid[i][j] = v[it];
                it ++;
            }
        }
        memset(dp, -1, sizeof(dp));
        return rec(0, n-1);
    }
};