class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
                    int idx=n-1;
        bool is=true;
            int ans=0;
            int len=0;
        for(auto x:nums){
        
            if(x!=0){
                is=false;
            }
           ans^=x;
           len++;

        }
        if(is )
        return 0;
        if(ans !=0){
            return len;
        }
        else{

            while(ans !=0){
                ans^=nums[idx];
                idx--;
            }
            


        }
        return idx;
        
    }
};