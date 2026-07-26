class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;

        long long a = 0;

        while (a * cost1 <= total) {
            long long rem = total - a * cost1;
            ans += rem / cost2 + 1;
            a++;
        }

        return ans;
    }
};