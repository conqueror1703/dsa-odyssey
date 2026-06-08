class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       long long total=0;
        sort(nums.begin(), nums.end());
        long long freq=1;

        int n = nums.size();
        long long  i=0;
   
   for(long long j=0;j<n;j++){
    total+=nums[j];
    while(j<n && ((nums[j]*(j-i+1)-total)>k) ){
        total-=nums[i];
        i++;
        


    }

    freq=max(j-i+1,freq);
   }




   







 
        return freq;
    }
};