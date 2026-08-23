class Solution {
public:
    bool sumGame(string num) {
        int cnta = 0;
        int cntb = 0;
        int suma = 0;
        int sumb = 0;

        int n = num.length();

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                cntb++;
            else
                sumb += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                cnta++;
            else
                suma += num[i] - '0';
        }

        if ((cnta + cntb) % 2 == 1)
            return true;

        if (2 * (sumb - suma) == 9 * (cnta - cntb))
            return false;

        return true;
    }
};