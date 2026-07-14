class Solution {
public:
int dp[201][201][201];

int  MOD=1e9+7;

   int solve(vector<int>& nums,int idx,int first,int second){
   if (idx == nums.size()) {
            if (first != 0 && second != 0 && first == second) {
                return 1;
            }
            return 0;
        }
        if(dp[idx][first][second] !=-1){
            return dp[idx][first][second];
        }
    int skip=solve(nums,idx+1,first,second);
    int take1=solve(nums,idx+1,__gcd(first,nums[idx]),second);
    int take2=solve(nums,idx+1,first,__gcd(second,nums[idx]));





return dp[idx][first][second]=(0LL+take1+take2+skip)%MOD;
   }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
       return solve(nums,0,0,0);
        
    }
};