
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>groups;
        int n = nums.size();
        for(int i=0; i<n; i++){
            auto idx = lower_bound(groups.begin(), groups.end(), nums[i]) - groups.begin();
            if(idx == groups.size())
                groups.push_back(nums[i]);
            else groups[idx] = nums[i];
        }

        return groups.size();
    }
};

