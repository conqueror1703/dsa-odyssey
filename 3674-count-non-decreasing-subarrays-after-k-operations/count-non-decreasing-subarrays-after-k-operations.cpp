class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long current_cost = 0;
        deque<int> dq;
        int r = n - 1;

        for (int l = n - 1; l >= 0; --l) {
            while (!dq.empty() && nums[dq.front()] < nums[l]) {
                int idx = dq.front();
                dq.pop_front();
                int next_idx = dq.empty() ? (r + 1) : dq.front();
                long long count = next_idx - idx;
                current_cost += count * (nums[l] - nums[idx]);
            }
            dq.push_front(l);

            while (current_cost > k) {
                int max_idx = dq.back();
                current_cost -= (nums[max_idx] - nums[r]);
                if (max_idx == r) {
                    dq.pop_back();
                }
                --r;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};