class Solution {
public:
    bool bloomed(vector<int>& bloomDay,int mid,int k,int m){
        int cons=0;
        int cnt=0;
        for(int i=0;i< bloomDay.size();i++){
            if( bloomDay[i]<=mid){
                cons++;
            }
            else{
                cons=0;
            }
            if(cons==k){
                cnt++;
                cons=0;

            }
        }
        return cnt>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int l=1;
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=h;
        while(l<h){
            int mid=l+(h-l)/2;
             if (1LL * m * k > n)
            return -1;

            if(bloomed(bloomDay , mid,k,m)){
                ans=mid;
                h=mid;
            }
            else{
                l=mid+1;
            }

        }
        return ans;
        
    }
};