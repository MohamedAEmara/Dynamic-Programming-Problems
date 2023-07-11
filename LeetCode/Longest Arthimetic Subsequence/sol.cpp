class Solution {
public:

    
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int>mp;
        int n = arr.size();
        mp[arr[n-1]] = 1;
        int res[n];
        res[n-1] = 1;

        for(int i=n-2; i>=0; i--) {
            if(mp.count(arr[i]+diff)) {
                mp[arr[i]] = mp[arr[i]+diff] + 1;
                res[i] = mp[arr[i]];
            }
            else {
                mp[arr[i]] = 1;
                res[i] = 1;
            }
        }    

        for(int i=0; i<n; i++)  
            cout << res[i] << " ";
        cout << endl;

        return *max_element(res, res+n);
    }
};