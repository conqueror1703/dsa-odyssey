class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=cost[i];

        }
        if(n<=2) return sum;
        sort(cost.begin(),cost.end());
        for(int i=n-3;i>=0;i-=3){
            sum-=cost[i];
        }
        return sum;
        
    }
};