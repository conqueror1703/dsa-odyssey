class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int island_count = 0;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] > 0) {
                    long long total_value = 0;
                    queue<pair<int, int>> q;

                    // Initialize BFS for this connected component
                    total_value += grid[r][c];
                    grid[r][c] = 0; // Mark as visited in-place
                    q.push({r, c});

                    while (!q.empty()) {
                        auto [curr_r, curr_c] = q.front();
                        q.pop();

                        for (int i = 0; i < 4; ++i) {
                            int nr = curr_r + dr[i];
                            int nc = curr_c + dc[i];

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                total_value += grid[nr][nc];
                                grid[nr][nc] = 0; // Mark as visited
                                q.push({nr, nc});
                            }
                        }
                    }

                    if (total_value % k == 0) {
                        island_count++;
                    }
                }
            }
        }

        return island_count;
    }
};