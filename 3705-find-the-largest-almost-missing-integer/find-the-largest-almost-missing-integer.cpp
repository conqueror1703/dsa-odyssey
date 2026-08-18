class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: k == 1
        // Every subarray has only one element,
        // so we need the largest element appearing exactly once.
        if (k == 1) {
            unordered_map<int, int> freq;

            for (int x : nums) {
                freq[x]++;
            }

            int ans = -1;

            for (auto& [x, count] : freq) {
                if (count == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        // Case 2: k == n
        // There is only one subarray, the entire array.
        // Therefore every element is present in exactly one subarray.
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 3: 1 < k < n
        // Only the first and last elements can appear
        // in exactly one subarray of size k.

        int first = nums[0];
        int last = nums[n - 1];

        int firstCount = 0;
        int lastCount = 0;

        for (int x : nums) {
            if (x == first)
                firstCount++;

            if (x == last)
                lastCount++;
        }

        int ans = -1;

        if (firstCount == 1) {
            ans = max(ans, first);
        }

        if (lastCount == 1) {
            ans = max(ans, last);
        }

        return ans;
    }
};