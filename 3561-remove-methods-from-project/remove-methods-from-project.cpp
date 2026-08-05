class Solution {
public:
    vector<int> remainingMethods(int n,int k,vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<bool>vis(n,false);

        for(auto &it:invocations){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
        }

        queue<int>q;
        q.push(k);
        vis[k]=true;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto &v:adj[u]){
                if(vis[v]==false){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }

        for(auto &it:invocations){
            int u=it[0];
            int v=it[1];

            if(vis[u]==false && vis[v]==true){
                vector<int>ans;

                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }

                return ans;
            }
        }

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(vis[i]==false){
                ans.push_back(i);
            }
        }

        return ans;
    }
};