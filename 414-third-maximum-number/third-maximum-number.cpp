class Solution {
public:
    int thirdMax(vector<int>& nums) {
         int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        for(auto x:s){
            pq.push(x);
            if(pq.size()>3){
                pq.pop();
            }
        }
       if(pq.size()>=3){
        return pq.top();
       }
       else{
        return *max_element(nums.begin(),nums.end());
       }
        
    }
};