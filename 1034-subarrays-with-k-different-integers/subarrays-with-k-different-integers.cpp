class Solution {
public:

int sw(vector<int>& nums,int k){
       int i=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        int j=0;
        int cnt=0;

        while(j<n){
            mp[nums[j]]++;
    while(mp.size()>k){
        mp[nums[i]]--;
        if(mp[nums[i]]==0){
        mp.erase(nums[i]);
 
        }
               i++;
    }
    cnt+=j-i+1;
    j++;

         







}

   return cnt;

}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
     return    sw(nums,k)-sw(nums,k-1);

     


        
        
    }
    
};