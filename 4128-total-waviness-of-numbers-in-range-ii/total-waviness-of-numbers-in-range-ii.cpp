class Solution {
public:
    using ll = long long;

    pair<ll, ll> dp[20][2][11][11][3][2];
    bool vis[20][2][11][11][3][2];

    pair<ll, ll> dp_func(string &s, bool tight, ll prev2, ll prev1, ll idx, ll len, bool lz) {
        if (idx == s.size()) return {1, 0};

        if (vis[idx][tight][prev2][prev1][len][lz])
            return dp[idx][tight][prev2][prev1][len][lz];

        vis[idx][tight][prev2][prev1][len][lz] = true;

        ll lb = 0;
        ll ub = tight ? s[idx] - '0' : 9;

        ll total_cnt = 0;
        ll total_wave = 0;

        for (ll dig = lb; dig <= ub; dig++) {
            bool new_tight = (tight && dig == ub);

            // leading zero case
            if (lz && dig == 0) {
                auto next = dp_func(s, new_tight, 10, 10, idx + 1, 0, 1);

                total_cnt += next.first;
                total_wave += next.second;
            }
            else {
                ll add = 0;

                // now prev1 can become peak or valley
                if (len >= 2) {
                    if (prev1 > prev2 && prev1 > dig) add = 1;
                    else if (prev1 < prev2 && prev1 < dig) add = 1;
                }

                auto next = dp_func(s, new_tight, prev1, dig, idx + 1, min(2LL, len + 1), 0);

                total_cnt += next.first;
                total_wave += next.second + add * next.first;
            }
        }

        return dp[idx][tight][prev2][prev1][len][lz] = {total_cnt, total_wave};
    }

    ll solve(ll n) {
        if (n <= 0) return 0;

        string s = to_string(n);

        memset(vis, false, sizeof(vis));

        return dp_func(s, 1, 10, 10, 0, 0, 1).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};