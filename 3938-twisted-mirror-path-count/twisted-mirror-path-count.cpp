class Solution {
    static constexpr int MOD = 1e9 + 7;
    int m, n;
    int memo[505][505];
    pair<int, int> next_step[505][505][2];
    bool resolved[505][505][2];

    pair<int, int> trace(int r, int c, int dir, const vector<vector<int>>& grid) {
        if (r >= m || c >= n) return {-1, -1};
        if (resolved[r][c][dir]) return next_step[r][c][dir];

        int nr = r, nc = c;
        if (dir == 0) nc++; // move right
        else nr++;          // move down

        if (nr >= m || nc >= n) {
            resolved[r][c][dir] = true;
            return next_step[r][c][dir] = {-1, -1};
        }

        if (grid[nr][nc] == 0) {
            resolved[r][c][dir] = true;
            return next_step[r][c][dir] = {nr, nc};
        }

        // Cell is a mirror: reflect direction (0 -> 1, 1 -> 0)
        int next_dir = 1 - dir;
        auto dest = trace(nr, nc, next_dir, grid);

        resolved[r][c][dir] = true;
        return next_step[r][c][dir] = dest;
    }

    int dfs(int r, int c, const vector<vector<int>>& grid) {
        if (r == m - 1 && c == n - 1) return 1;
        if (memo[r][c] != -1) return memo[r][c];

        long long ways = 0;

        // Move right
        auto [r_right, c_right] = trace(r, c, 0, grid);
        if (r_right != -1 && c_right != -1) {
            ways = (ways + dfs(r_right, c_right, grid)) % MOD;
        }

        // Move down
        auto [r_down, c_down] = trace(r, c, 1, grid);
        if (r_down != -1 && c_down != -1) {
            ways = (ways + dfs(r_down, c_down, grid)) % MOD;
        }

        return memo[r][c] = ways;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(memo, -1, sizeof(memo));
        memset(resolved, false, sizeof(resolved));

        return dfs(0, 0, grid);
    }
};