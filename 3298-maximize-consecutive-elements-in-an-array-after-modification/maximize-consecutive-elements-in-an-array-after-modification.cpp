
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> dp(maxi + 2, 0);

        int ans = 0;

        for (int num : nums) {

      
            dp[num + 1] = max(dp[num + 1], dp[num] + 1);

           
            dp[num] = max(dp[num], dp[num - 1] + 1);

            ans = max(ans, max(dp[num], dp[num + 1]));
        }

        return ans;
    }
};
