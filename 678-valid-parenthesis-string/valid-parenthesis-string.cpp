class Solution {
public:
    bool checkValidString(string s) {
        int cnt1 = 0;
        int cnt3 = 0;

        for (char c : s) {
            if (c == '(') {
                cnt1++;
            }
            else if (c == '*') {
                cnt3++;
            }
            else {
                if (cnt1 > 0) {
                    cnt1--;
                }
                else if (cnt3 > 0) {
                    cnt3--;
                }
                else {
                    return false;
                }
            }
        }

        cnt1 = 0;
        cnt3 = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')') {
                cnt1++;
            }
            else if (s[i] == '*') {
                cnt3++;
            }
            else {
                if (cnt1 > 0) {
                    cnt1--;
                }
                else if (cnt3 > 0) {
                    cnt3--;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};