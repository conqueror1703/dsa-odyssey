class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;

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
            if(ce>=ns){
            intervals[i][1]=max(ce,ne);
            j++;
                
            }

            else{
                  ans.push_back(intervals[i]);
                i=j;
                j++;
               

            }



        }
        ans.push_back(intervals[i]);
        return ans;
        
    }
};