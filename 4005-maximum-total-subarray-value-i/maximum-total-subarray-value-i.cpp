class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long ans = (long long)(nums.back()-nums.front())* (long long)k;
        return ans;
        
    }
};