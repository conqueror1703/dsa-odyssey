class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long sum = 0;
            for (int num : nums) {
                sum += (num + mid - 1) / mid;  // ceil division
            }

            if (sum <= threshold) {
                ans = mid;        // candidate found, try smaller divisor
                right = mid - 1;
            } else {
                left = mid + 1;   // need larger divisor
            }
        }

        return ans;
    }
};
