
// Author: MohamedEmara
class Solution {
public:
    int n;
    int arr[5005];
    int dp[5005][2];	// idx, state (carry item or not)

    int rec(int idx, int carry) // 1 for buy -  2 for sell - 3 for skip
    {
        if(idx >= n)
            return 0;
        int &ret = dp[idx][carry];
        if(~ret)
            return ret;
        if(carry == 0)      // I carry nothing --> I can buy this 
        {
            ret = max(rec(idx+1, 0), -arr[idx]+rec(idx+1, 1));
        }
        else if(carry == 1)
        {
            ret = max(rec(idx+1, 1), arr[idx]+rec(idx+2, 0));
        }

        return ret;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        for(int i=0; i<n; i++)
            arr[i] = prices[i];

        memset(dp, -1, sizeof(dp));
        int mx = 0;
        mx = max(mx, rec(0, 0));
        memset(dp, -1, sizeof(dp));
        mx = max(mx, -arr[0]+rec(1, 1));
        return mx;
    }
};

