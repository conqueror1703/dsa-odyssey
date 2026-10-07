class Solution {
public:
    int n;
    int maxlen;
    unordered_set<string> st;

    void solve(string &s, int idx, string &curr, int cnt) {

        if (cnt < 0)
            return;


        if (idx == n) {
            if (cnt == 0) {
                if (curr.length() > maxlen) {
                    maxlen = curr.length();
                    st.clear();
                }

                if (curr.length() == maxlen) {
                    st.insert(curr);
                }
            }
            return;
        }


        if (s[idx] != '(' && s[idx] != ')') {
            curr.push_back(s[idx]);

            solve(s, idx + 1, curr, cnt);

            curr.pop_back();
            return;
        }

      
        curr.push_back(s[idx]);

        solve(
            s,
            idx + 1,
            curr,
            cnt + (s[idx] == '(' ? 1 : -1)
        );

        curr.pop_back();


        solve(s, idx + 1, curr, cnt);
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        maxlen = 0;

        string curr = "";

        solve(s, 0, curr, 0);

        return vector<string>(st.begin(), st.end());
    }
};