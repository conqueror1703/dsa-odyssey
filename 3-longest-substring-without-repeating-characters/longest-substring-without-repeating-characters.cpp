class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            unordered_set<char> st;

            for (int j = i; j < s.length(); j++) {
                if (st.find(s[j]) != st.end()) {
                    ans = max(ans, j - i);
                    break;
                }
                st.insert(s[j]);
            }

            // handle case when no duplicate found till end
            ans = max(ans, (int)st.size());
        }

        return ans;
    }
};
