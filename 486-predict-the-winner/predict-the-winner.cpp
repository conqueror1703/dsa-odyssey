class Solution {
public:
int solve(int i,int j,vector<int>& nums){
        
    if(i==j){
        return nums[i];
    }
    if(i>j){
        return 0;
    }

    int takei=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
    int takej=nums[j]+min(solve(i,j-2,nums),solve(i+1,j-1,nums));
   
   return max(takei,takej);


}



    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
                int total=accumulate(nums.begin(),nums.end(),0);
        int p1=solve(0,n-1,nums);
        int p2=total-p1;
        return p1>=p2;
    }
};