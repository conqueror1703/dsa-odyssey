class Solution {
public:
void gen(vector<int>& nums, int i, vector<int>&ans, vector<vector<int>>&allsub){
    if(i==nums.size()){
        allsub.push_back(ans);
        return ;
    }
    ans.push_back(nums[i]);
    gen(nums, i+1, ans, allsub);
    ans.pop_back();
    int idx=i+1;

    while(idx<nums.size() && nums[idx-1]==nums[idx]){
        idx++;
    }
     gen(nums, idx, ans, allsub);




}






    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int>>allsub;
        vector<int>ans;
         gen(nums, 0, ans, allsub);

         return allsub;
        
    }
};