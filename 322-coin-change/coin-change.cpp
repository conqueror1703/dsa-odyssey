class Solution {
public:

    vector<int> dp;

    int solve(vector<int>& coins, int amount) {

        // base case
        if (amount == 0)
            return 0;

        // impossible case
        if (amount < 0)
            return 1e9;

        // already computed
        if (dp[amount] != -1)
            return dp[amount];

        int ans = 1e9;

        // try every coin
        for (int coin : coins) {

            ans = min(ans, 1 + solve(coins, amount - coin));
        }

        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {

        dp.resize(amount + 1, -1);

        int ans = solve(coins, amount);

        if (ans >= 1e9)
            return -1;

        return ans;
    }
};