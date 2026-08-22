class Solution {
public:
    bool checkDivisibility(int n) {
         int temp=n;
        int prod=1;
        int sum=0;
        while(n){
           
            sum+=n%10;
            prod*=n%10;
            n/=10;

        }
        if(temp %(sum+prod)==0){
            return true;
        }
        return false;
        
    }
};