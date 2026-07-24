class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
          int n = nums.size();
        vector<bool> s1(1<<11,0);
        vector<bool> s2(1<<11, 0);

      

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                s1[nums[i] ^ nums[j]] = 1;
            }
        }// all possible pair of xor

        for (int x = 0; x < 1<<11; x++) {
            if (!s1[x]) continue;

            for (int i = 0; i < n; i++) {
                s2[x ^ nums[i]] = 1;
            }
        }

     return count(s2.begin(), s2.end(), 1);;
    }
};