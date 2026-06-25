class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n + 2;

        vector<int> bit(2 * n + 5, 0);

        auto update = [&](int idx) {
            while (idx < bit.size()) {
                bit[idx]++;
                idx += idx & -idx;
            }
        };

        auto query = [&](int idx) {
            int ans = 0;
            while (idx > 0) {
                ans += bit[idx];
                idx -= idx & -idx;
            }
            return ans;
        };

        long long ans = 0;
        int pref = 0;

        update(pref + offset);

        for (int x : nums) {
            if (x == target) pref++;
            else pref--;

            ans += query(pref + offset - 1);

            update(pref + offset);
        }

        return ans;
    }
};