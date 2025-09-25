class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        int last = 0;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < triangle[i].size(); j++) {
                int cur = triangle[i][j];
                if(j-1 >= 0) {
                    if(j > last) dp[i][j] = dp[i-1][j-1] + cur; // equation 3 - last entry
                    else dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + cur; // equation 1
                }
                else {
                    dp[i][j] = dp[i-1][j] + cur; // equation 2 - first entry
                }
            }
            last = triangle[i].size()-1;
        }

        // get a minimum distance path.
        for(int i = 0; i < triangle[n-1].size(); i++) {
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};