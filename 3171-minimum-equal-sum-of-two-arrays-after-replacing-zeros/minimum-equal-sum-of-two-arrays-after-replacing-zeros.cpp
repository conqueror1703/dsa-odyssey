class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int z1 = 0, z2 = 0;

        for (int x : nums1) {
            if (x == 0) z1++;
            else sum1 += x;
        }
        for (int x : nums2) {
            if (x == 0) z2++;
            else sum2 += x;
        }

        // Case 1: No zeros at all → sums fixed
        if (z1 == 0 && z2 == 0) {
            return (sum1 == sum2 ? sum1 : -1);
        }

        long long min1 = sum1 + z1;  // all zeros replaced with 1
        long long min2 = sum2 + z2;

        if (min1 == min2) return min1;

        if (min1 < min2) {
            return (z1 > 0 ? min2 : -1);
        } else { // min2 < min1
            return (z2 > 0 ? min1 : -1);
        }
    }
};

