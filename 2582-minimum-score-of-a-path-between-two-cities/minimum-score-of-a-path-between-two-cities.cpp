class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto& road : roads) {
            int a = road[0], b = road[1], dist = road[2];
            graph[a].push_back({b, dist});
            graph[b].push_back({a, dist});
        }

        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        int ans = INT_MAX;

        while (!q.empty()) {
            int city = q.front();
            q.pop();

            for (auto& [nextCity, dist] : graph[city]) {
                ans = min(ans, dist);

                if (!visited[nextCity]) {
                    visited[nextCity] = true;
                    q.push(nextCity);
                }
            }
        }

        return ans;
    }
};