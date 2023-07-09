class Solution {
public:
    int n;
    int arr[1005];
    int dp[1005];



    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();

        memset(dp, -1, sizeof(dp));
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            int mx = -1e9;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] - nums[i] >= -target && nums[j] - nums[i] <= target) {
                    if(dp[j] != -1) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[0];
    }
};