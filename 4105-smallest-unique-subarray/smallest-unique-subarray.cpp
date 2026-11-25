class Solution {
    using ull = unsigned long long;

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        // Precompute powers for two independent polynomial hashes
        const ull B1 = 1315423911ULL, M1 = 1000000007ULL;
        const ull B2 = 1000003ULL,    M2 = 1000000009ULL;

        vector<ull> p1(n + 1, 1), p2(n + 1, 1);
        vector<ull> h1(n + 1, 0), h2(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            p1[i + 1] = (p1[i] * B1) % M1;
            p2[i + 1] = (p2[i] * B2) % M2;
            h1[i + 1] = (h1[i] * B1 + nums[i]) % M1;
            h2[i + 1] = (h2[i] * B2 + nums[i]) % M2;
        }

        auto get_hash = [&](int l, int r) -> ull {
            ull v1 = (h1[r] + M1 - (h1[l] * p1[r - l]) % M1) % M1;
            ull v2 = (h2[r] + M2 - (h2[l] * p2[r - l]) % M2) % M2;
            return (v1 << 32) | v2;
        };

        auto check = [&](int len) -> bool {
            int count = n - len + 1;
            vector<ull> hashes(count);
            for (int i = 0; i < count; ++i) {
                hashes[i] = get_hash(i, i + len);
            }
            sort(hashes.begin(), hashes.end());

            for (int i = 0; i < count; ++i) {
                bool same_prev = (i > 0 && hashes[i] == hashes[i - 1]);
                bool same_next = (i + 1 < count && hashes[i] == hashes[i + 1]);
                if (!same_prev && !same_next) {
                    return true;
                }
            }
            return false;
        };

        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};