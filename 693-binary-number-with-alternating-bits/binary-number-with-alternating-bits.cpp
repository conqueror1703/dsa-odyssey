class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n > 0) {
            if((n ^ (n >> 1)) % 2 == 0)
                return 0;
            n >>= 1;
        }

        return 1;
    }
};