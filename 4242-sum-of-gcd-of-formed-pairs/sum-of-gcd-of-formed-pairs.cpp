class Solution {
public:
    long long gcdSum(vector<int >& nums) {
         int  n=nums.size();
        int  mx=INT_MIN;
        vector<int >prefixGcd(n);
        long long  sum=0;
       
        for(long long  i=0;i<n;i++){
            mx=max(mx,nums[i]);
            prefixGcd[i]=gcd(nums[i],mx);

        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long  l=0;
        long long  r=n-1;
        while(l<r){
            sum+=gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;

        }
        return sum;

        
    }
};