class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mp;
        int n=ceil(nums.size()/3);
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto x : mp){
            if (x.second>n){
                ans.push_back(x.first);
            }
           
        }
        return ans ;
    }
};