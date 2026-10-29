class Solution {
public:

int t[21][1001];

    int solve( vector<int>& arr,int sum,int n) {
        if(n == 0)
            return (sum == 0) ? 1 : 0;

        if(t[n][sum] != -1) {
            return t[n][sum];
        }

        int skip = solve(arr,sum,n-1);

        int take = 0;
        if(arr[n-1] <= sum) {
            take = solve(arr, sum - arr[n-1], n-1);
        }

        return t[n][sum] = (take + skip);
    }






    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        int s=accumulate(begin(nums),end(nums),0);
         target=abs(target);
        if((s+target)%2 !=0){
            return 0;
        }

        int s1=(s+target)/2;
        return solve(nums,s1,n);





        
    }
};