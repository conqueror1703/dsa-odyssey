class Solution {
    int digisum(int k){
        int val=0;
        while(k){
            val+=k%10;
            k/=10;

        }
        return val;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(digisum(nums[i])==i){
                return i;
            }

        }
        return -1;

        
    }
};