class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0, max_freq = 0, max_len = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            max_freq = max(max_freq, freq[s[right]]);

            while ((right - left + 1) - max_freq > k) {
                freq[s[left]]--;
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
