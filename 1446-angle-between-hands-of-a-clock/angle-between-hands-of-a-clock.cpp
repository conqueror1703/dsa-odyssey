class Solution {
public:
    double angleClock(int hour, int minutes) {
    
        double ans=(30*hour -5.5*minutes);

        if(abs(ans)<=180)
        return abs(ans);
        else 
        return (360-abs(ans));
        
    }
};