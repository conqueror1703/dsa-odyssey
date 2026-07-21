class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ans = 0, curr = 0, prev = 0, one = 0;
        int n = s.size(), i = 0;

        while (i < n) {
            if (s[i] == '0') {
                curr++;
                i++;
            } else {
                if (prev && curr) ans = max(ans, prev + curr);

                prev = curr;
                curr = 0;

                while (i < n && s[i] == '1') {
                    one++;
                    i++;
                }
            }
        }

        if (prev && curr) {
            ans = max(ans, prev + curr);
        }

        return one + ans;
    }
};