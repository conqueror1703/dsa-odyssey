class Solution {
public:

    int solve(vector<int>& nums, int l, int r) {

        int n = r - l + 1;

        vector<int> dp(n + 1, 0);

        dp[1] = nums[l];

        for (int i = 2; i <= n; i++) {

            dp[i] = max(dp[i - 1],
                        dp[i - 2] + nums[l + i - 1]);
        }

        return dp[n];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return nums[0];
        int case1 = solve(nums, 0, n - 2);
        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};