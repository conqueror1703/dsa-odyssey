class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int tsum=0;
        vector<int>ans(n);
        vector<int>pref(n);
        for(int i=0;i<n;i++){
            tsum+=nums[i];
            if(i==0){
                pref[i]=nums[i];
            }
            else
            pref[i]=pref[i-1]+nums[i];
        }
        for(int j=0;j<n;j++){
            if(j!=0){
                ans[j]=abs(tsum-pref[j]-pref[j-1]);
            }
            else
            ans[j]=tsum-nums[0];
        }
        return ans;
    }
};