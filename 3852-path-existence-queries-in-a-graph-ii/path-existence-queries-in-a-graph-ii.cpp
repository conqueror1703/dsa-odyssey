class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        vector<int> val(n), pos(n);

        for (int i = 0; i < n; i++) {
            val[i] = v[i].first;
            pos[v[i].second] = i;
        }

        vector<int> comp(n, 0);
        for (int i = 1; i < n; i++) {
            comp[i] = comp[i - 1];
            if (val[i] - val[i - 1] > maxDiff) {
                comp[i]++;
            }
        }

        const int LOG = 18;
        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            int r = upper_bound(val.begin(), val.end(), val[i] + maxDiff) - val.begin() - 1;
            up[0][i] = r;
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int vtx = q[1];

            if (u == vtx) {
                ans.push_back(0);
                continue;
            }

            int l = pos[u];
            int r = pos[vtx];

            if (l > r) swap(l, r);

            if (comp[l] != comp[r]) {
                ans.push_back(-1);
                continue;
            }

            int cur = l;
            int dist = 0;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][cur] < r) {
                    cur = up[j][cur];
                    dist += (1 << j);
                }
            }

            ans.push_back(dist + 1);
        }

        return ans;
    }
};