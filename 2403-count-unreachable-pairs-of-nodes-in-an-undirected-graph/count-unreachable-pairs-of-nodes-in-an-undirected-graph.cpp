class Solution {
public:
vector<int> parent;
vector<int> rank;

int find (int x) {
    if (x == parent[x]) 
        return x;

    return parent[x] = find(parent[x]);
}

void Union (int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent) 
        return;

    if(rank[x_parent] > rank[y_parent]) {
        parent[y_parent] = x_parent;
    } else if(rank[x_parent] < rank[y_parent]) {
        parent[x_parent] = y_parent;
    } else {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
         parent.resize(n);
        int comp=n;
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
         for(auto &vec :edges){
          int u=vec[0];
          int v=vec[1];
          Union(u,v);
          }
          unordered_map<int,int>mp;
          for(int i=0;i<n;i++){
            int paar=find(i);
            mp[paar]++;

          }
          long long ans=0;
          long long rem=n;

          for(auto &it :mp){
            long long size=it.second;
            ans+=size*(rem-size);
            rem-=size;

          }





return ans;



        
    }
};