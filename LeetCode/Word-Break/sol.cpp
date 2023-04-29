// Authour: MohamedEmara

class Solution {
public:

int n, len;
vector<string>v;
string s;
int dp[305][1005];
//  index, word
// try to insert every word (if we can) & see if there is 
// a solution that ends up that every subarray is a word 
// from the given dictionary. 

int rec(int idx, int curr)
{
    if(idx == n)    // if we reach the end --> it's a valid sol 
        return 1;   // & return 1
	
    if(idx > n)     // If the index exceeded the last element 
        return 0;   // so, it doesn't fit

    // memoization:
    int &ret = dp[idx][curr];

    if(~ret)
        return ret;
    
    ret = 0;

    // try all strings in the wordDict that match our string
    for(int i=1; i<=len; i++)
    {
        int currLen = v[i].length();
        if(currLen + idx <= n && s.substr(idx, currLen) == v[i])
        {
			ret = max(ret, rec(idx+currLen, i));
        }
    }

    return ret;
}
    
bool wordBreak(string ss, vector<string>& wordDict) {
        n = ss.length();
        len = wordDict.size();
		v.push_back("lkjsdf");
        for(auto it : wordDict)
        {
            v.push_back(it);
        }
        memset(dp, -1, sizeof(dp));
        s = ss;
		return rec(0, 0);
}

};
