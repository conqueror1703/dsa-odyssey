class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            if(abs(ans)>INT_MAX/10){
            return 0;
        }
     int last = x % 10;
        ans*=10;
        ans+=last;
        
        x/=10;
        }
        return ans;
        
    }
};