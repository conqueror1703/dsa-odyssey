class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int curr = 1;

        for (auto x : arr) {
            while (curr < x) {
                k--;

                if (k == 0) {
                    return curr;
                }

                curr++;
            }

            if (curr == x) {
                curr++;
            }
        }

        return curr + k - 1;
    }
};