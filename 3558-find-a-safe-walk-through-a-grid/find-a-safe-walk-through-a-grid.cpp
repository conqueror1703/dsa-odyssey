class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;

        dist[0][0] = grid[0][0];
        dq.push_back({0, 0});

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

                int cost = grid[nx][ny];
                int newDist = dist[x][y] + cost;

                if (newDist < dist[nx][ny]) {
                    dist[nx][ny] = newDist;

                    if (cost == 0) {
                        dq.push_front({nx, ny});
                    } else {
                        dq.push_back({nx, ny});
                    }
                }
            }
        }

        return dist[m - 1][n - 1] < health;
    }
};