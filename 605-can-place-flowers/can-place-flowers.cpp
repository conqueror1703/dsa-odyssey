class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int size = flowerbed.size();

        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 0) {
                bool left = (i == 0 || flowerbed[i - 1] == 0);
                bool right = (i == size - 1 || flowerbed[i + 1] == 0);

                if (left && right) {
                    flowerbed[i] = 1;
                    cnt++;
                }
            }

            if (cnt >= n) return true;
        }

        return cnt >= n;
    }
};