class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evencnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if((to_string(nums[i]).size())%2==0 )
            evencnt++;
            
        }
        return evencnt;
        
    }
};