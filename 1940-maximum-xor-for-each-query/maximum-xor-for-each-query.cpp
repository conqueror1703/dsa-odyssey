class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> answer;
        int max_possible_val = (1 << maximumBit) - 1;
        int current_xor_sum = 0;
        for (int x : nums) {
            current_xor_sum ^= x;
        }
        for (int i = n - 1; i >= 0; i--) {
            answer.push_back(current_xor_sum ^ max_possible_val);
            current_xor_sum ^= nums[i];
        }
        
        return answer;
    }
};