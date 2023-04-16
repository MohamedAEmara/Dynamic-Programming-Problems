
// Author: Mohamed Emara

class Solution {
public:
    int dp[20005];   
    int n;
    int freq[10005];
    int rec(int idx)
    {
        if(idx > n)
            return 0;
        if(idx == n)
            return freq[idx] * idx;
        int &ret = dp[idx];
        if(~ret)
            return ret;

        int mx = -1e9;
        // skip
        mx = max(mx, rec(idx+3) + freq[idx+1]*(idx+1));
        // use
        mx = max(mx, rec(idx+2) + freq[idx]*(idx));

        return ret = mx;
    }

    int deleteAndEarn(vector<int>& nums) {
        n = 10004;
      
        memset(freq, 0, sizeof(freq));
        for(int i=0; i<nums.size(); i++)
            freq[nums[i]] ++;
        memset(dp, -1, sizeof(dp));
        return rec(1);
    }
};

