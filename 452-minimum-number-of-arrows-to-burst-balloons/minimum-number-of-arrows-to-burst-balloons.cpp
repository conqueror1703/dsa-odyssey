class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        // 1,6. 2,8 7,12 10,16
        // 1,10 3,9 4,11 6,7 6,9 8,12 9,12
        int n=points.size();

        int i=0;
        int j=1;
        int cnt=1;

        while(j<n){
            vector<int>curr=points[i];
            vector<int>nxt=points[j];
            int cs=curr[0];
            int ce=curr[1];
             int ns=nxt[0];
            int ne=nxt[1];
            if(ce>=ns){
                 points[i][1] = min(ce, ne);
               j++;
            }
           else{
            cnt++;
            i=j;
            j++;
           }


        }
        return cnt;
        
    }
};