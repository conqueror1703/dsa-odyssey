class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=low;
        while(low<=high){
        int mid = low + (high - low) / 2;
       long long total_hr=0;
        for(int bananas:piles){
            total_hr +=(bananas+mid-1)/mid;
        }
        if(total_hr<=h){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
        }
        return low;



        
    }
};