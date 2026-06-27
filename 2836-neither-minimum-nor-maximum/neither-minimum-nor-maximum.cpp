class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
         int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>2)
            pq.pop();
        }
        if(nums.size()>2)
      return pq.top();
        else 
        return -1;
    }
};