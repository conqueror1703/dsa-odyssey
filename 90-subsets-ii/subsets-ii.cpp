class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int idx, vector<int>& temp) {
        if (idx >= nums.size()) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp);
        temp.pop_back();

        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
            idx++;
        }

        solve(nums, idx + 1, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        solve(nums, 0, temp);

        return result;
    }
};