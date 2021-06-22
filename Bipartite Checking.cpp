namespace Bipartite{
    std::vector<int> adj[maxn];
    std::vector<int> vis, col;
    void Clear(int n){
        for(int i = 0; i<=n; i++){
            adj[i].clear();
        }
        vis.assign(n, 0);
        col.assign(n, -1);
    }
 
    void dfs(int x, int curcol, int& bi_tie){
        vis[x] = 1;
        col[x] = curcol;
        for(auto v : adj[x]){
            if(col[v] == -1)dfs(v,curcol ^ 1, bi_tie);
            else if(col[v] == curcol)bi_tie = 0;
        }
    }
    int is_bipartie(int v){
        int bi_tie = 1;
        dfs(0,0,bi_tie);
        return bi_tie;
    }
 
    //check range
}using namespace Bipartite;
