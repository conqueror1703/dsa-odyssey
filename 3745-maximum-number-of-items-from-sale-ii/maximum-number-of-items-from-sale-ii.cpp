
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        vector<int> freq(n + 1, 0);
        vector<int> gain(n + 1, 0);

        int minPrice = INT_MAX;

        // Step 1: Count frequency of each factor
        for (auto &it : items) {
            freq[it[0]]++;
            minPrice = min(minPrice, it[1]);
        }

        // Step 2: Calculate gain for every factor
        for (int f = 1; f <= n; f++) {

            for (int j = f; j <= n; j += f) {
                gain[f] += freq[j];
            }

            gain[f]--;
        }

        // Step 3: Store useful promotional copies
        vector<pair<int, int>> promo;

        for (auto &it : items) {

            int factor = it[0];
            int price = it[1];

            if (gain[factor] > 0 &&
                1LL * price < 2LL * minPrice) {

                promo.push_back({price, gain[factor]});
            }
        }

        // Step 4: Sort by price
        sort(promo.begin(), promo.end());

        long long ans = 0;

        // Step 5: Purchase promotional copies first
        for (auto &p : promo) {

            int price = p.first;
            int cnt = p.second;

            if (budget < price) break;

            int buy = min(cnt, budget / price);

            ans += 2LL * buy;
            budget -= buy * price;
        }

        // Step 6: Spend remaining budget on cheapest item
        ans += budget / minPrice;

        return (int)ans;
    }
};
