class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long x = 100000;

        return max({
            1LL * nums[0] * nums[1] * x,
            1LL * nums[n - 1] * nums[n - 2] * x,
            1LL * nums[0] * nums[n - 1] * (-x)
        });
    }
};