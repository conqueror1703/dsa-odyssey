class Solution {
    static constexpr int MOD = 1e9 + 7;

    struct SegmentTree {
        int n;
        vector<long long> sum_sq;
        vector<long long> sum_val;
        vector<long long> lazy;

        SegmentTree(int size) {
            n = size;
            sum_sq.assign(4 * n, 0);
            sum_val.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }

        void apply(int node, int l, int r, long long val) {
            val %= MOD;
            long long len = r - l + 1;
            
            long long term1 = (2 * val % MOD) * sum_val[node] % MOD;
            long long term2 = (val * val % MOD) * len % MOD;
            sum_sq[node] = (sum_sq[node] + term1 + term2) % MOD;

            sum_val[node] = (sum_val[node] + val * len) % MOD;

            lazy[node] = (lazy[node] + val) % MOD;
        }

        void push_down(int node, int l, int r) {
            if (lazy[node] != 0) {
                int mid = l + (r - l) / 2;
                apply(2 * node, l, mid, lazy[node]);
                apply(2 * node + 1, mid + 1, r, lazy[node]);
                lazy[node] = 0;
            }
        }

        void push_up(int node) {
            sum_sq[node] = (sum_sq[2 * node] + sum_sq[2 * node + 1]) % MOD;
            sum_val[node] = (sum_val[2 * node] + sum_val[2 * node + 1]) % MOD;
        }

        void update(int node, int l, int r, int ql, int qr, long long val) {
            if (ql <= l && r <= qr) {
                apply(node, l, r, val);
                return;
            }
            push_down(node, l, r);
            int mid = l + (r - l) / 2;
            if (ql <= mid) {
                update(2 * node, l, mid, ql, qr, val);
            }
            if (qr > mid) {
                update(2 * node + 1, mid + 1, r, ql, qr, val);
            }
            push_up(node);
        }

        void add_range(int ql, int qr, long long val) {
            if (ql <= qr) {
                update(1, 0, n - 1, ql, qr, val);
            }
        }

        long long get_total_sq() {
            return sum_sq[1];
        }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        SegmentTree tree(n);
        unordered_map<int, int> last_pos;

        long long total_ans = 0;

        for (int i = 0; i < n; ++i) {
            int prev_idx = last_pos.count(nums[i]) ? last_pos[nums[i]] : -1;
            
            tree.add_range(prev_idx + 1, i, 1);
            total_ans = (total_ans + tree.get_total_sq()) % MOD;

            last_pos[nums[i]] = i;
        }

        return (total_ans % MOD + MOD) % MOD;
    }
};