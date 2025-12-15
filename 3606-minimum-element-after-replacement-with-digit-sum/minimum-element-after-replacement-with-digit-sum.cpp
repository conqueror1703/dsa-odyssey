class Solution {
public:
int getsum(int num){
    int ans=0;
    while(num){
         ans += (num%10);
        num /=10;
    }
    return ans;
}
    int minElement(vector<int>& nums) {
       int n=nums.size();
       for(int i=0;i<n;i++){
        nums[i]=getsum(nums[i]);
       }
       return *min_element(nums.begin(),nums.end());
        
    }
};