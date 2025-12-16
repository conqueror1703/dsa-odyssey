class Solution {
public:
    double myPow(double x, int n) {
        long long k=n;
        double ans=1.0;
        if(k<0){
            k=-1*k;;
        }
        while(k){
        if(k%2==0){
            x=x*x;
            k=k/2;
        }
        else{
            ans=ans*x;
            k=k-1;
        }
        }
        if(n<0)ans=(double)(1.0)/(double)(ans);
        return ans;
    }
};