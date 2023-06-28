class Solution {
public:

    int n, m;
    string s1, s2;
    int dp[505][505][5];

    int rec(int i, int j, int state) {
        if(j == m)
            return (n - i);
        if(i == n)
            return (m - j);
        int &ret = dp[i][j][state];
        if(~ret)
            return ret;
        if(s1[i] == s2[j]) 
            ret = rec(i+1, j+1, 4);
        else {
            int op1 = 1 + rec(i, j+1, 1);
            int op2 = 1 + rec(i+1, j, 2);
            int op3 = 1 + rec(i+1, j+1, 3);
            ret = min({op1, op2, op3});
        }

        return ret;
            

    }
    int minDistance(string word1, string word2) {
        n = word1.length();
        m = word2.length();
        s1 = word1;
        s2 = word2;
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0);
    }
};