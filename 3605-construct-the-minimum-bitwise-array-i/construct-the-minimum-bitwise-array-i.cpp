class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if ((nums[i] & 1) ^ 1) {
                nums[i] = -1;
                continue;
            }
            for (int j = 0; j <= nums[i]; ++j)
            {
                if ((j | (j + 1)) == nums[i]) {
                    nums[i] = j;
                    break;
                }
            }
        }
        return nums;
    }
};
