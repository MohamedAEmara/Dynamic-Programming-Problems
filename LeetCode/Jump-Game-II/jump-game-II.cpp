

class Solution {
public:

int n;
vector<int>v;
int dp[10009];

int rec(int idx){
    if(idx >= n-1)
        return 0;
    int &ret = dp[idx];
    if(~ret)
        return ret;
    int mn = 1e8;
    for(int i=1; i<=v[idx]; i++)
    {
        mn = min(mn, 1 + rec(idx+i));
    }
    ret = mn;
    return ret;
}


int jump(vector<int>& nums) {
    n = nums.size();
    v = nums;
    memset(dp, -1, sizeof(dp));
    return rec(0);
}

    
};

