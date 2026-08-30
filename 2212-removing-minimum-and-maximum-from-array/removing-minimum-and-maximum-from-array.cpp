class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        int mini=min_element(nums.begin(),nums.end())-nums.begin();
        int maxi=max_element(nums.begin(),nums.end())-nums.begin();
       int left = min(mini, maxi);
        int right = max(mini, maxi);

        return min({
            right + 1,              
            n - left,             
            left + 1 + n - right });
        
    }
};