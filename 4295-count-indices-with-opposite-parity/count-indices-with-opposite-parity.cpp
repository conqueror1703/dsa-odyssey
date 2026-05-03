class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> parity(n), answer(n);

        for (int i = 0; i < n; i++) {
            parity[i] = nums[i] % 2;
        }

        int evenCnt = 0, oddCnt = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (parity[i] == 0) {
                answer[i] = oddCnt;
                evenCnt++;
            } else {
                answer[i] = evenCnt;
                oddCnt++;
            }
        }

        return answer;
    }
};
