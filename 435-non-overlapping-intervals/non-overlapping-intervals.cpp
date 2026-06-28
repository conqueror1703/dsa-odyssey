class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end());
        int n=intervals.size();

        int i=0;
        int j=1;
        int cnt=0;

        while(j<n){
            vector<int>curr=intervals[i];
            vector<int>nxt=intervals[j];
            int cs=curr[0];
            int ce=curr[1];
             int ns=nxt[0];
            int ne=nxt[1];
            if(ce<=ns){
                i=j;
                j++;
            }
            else if(ne>=ce){
                j++;
                cnt++;

            }
            else{
                i=j;
                j++;
                cnt++;

            }



        }
        return cnt;
        
    }
};