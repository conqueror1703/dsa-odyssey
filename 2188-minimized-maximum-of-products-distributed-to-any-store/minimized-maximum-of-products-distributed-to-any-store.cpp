class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long stores = 0;
            for (int q : quantities) {
                stores += (q + mid - 1) / mid;  // ceil(q/mid)
            }

            if (stores <= n) {
                ans = mid;      // feasible, try smaller max
                right = mid - 1;
            } else {
                left = mid + 1; // too small, increase mid
            }
        }

        return ans;
    }
};
