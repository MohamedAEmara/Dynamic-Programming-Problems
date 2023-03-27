
class Solution {
public:

    int n, m;
    int dp[205][205];
    int arr[205][205];

    bool valid(int i, int j)
    {
        if(i >= n || j >= m)
            return false;
        return true;
    }

    int rec(int i, int j)
    {
        if(!valid(i, j))
            return 1e8;
        
        if(i == n-1 && j == m-1)
            return arr[i][j];

        int &ret = dp[i][j];
        if(~ret)
            return ret;
    
        return ret = min(rec(i+1, j) + arr[i][j], rec(i, j+1) + arr[i][j]);
        

    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();    
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; j++)
            {
                arr[i][j] = grid[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        return rec(0, 0);
    }
};


