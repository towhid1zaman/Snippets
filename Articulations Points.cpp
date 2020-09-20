int lowTime[maxn], visitTime[maxn], d, n, m;
vi adj[maxn];
set<int>st;

void RESET(){
	for(int i = 0; i<=n+5; i++){
		adj[i].clear();
		visitTime[i] = 0;
		lowTime[i] = 0;
	}
	st.clear();
}

void dfs(int u){
	lowTime[u] = visitTime[u] = ++d;
	int cnt = 0;
	for(auto v: adj[u]){
		if(!visitTime[v]){
			++cnt;
			dfs(v);
			lowTime[u] = min(lowTime[u], lowTime[v]);

			if(u==1 and cnt>1 or (u !=1 and visitTime[u]<=lowTime[v])){
				st.insert(u);
			}
		}
		else{
			// Visited , that means its a back edge
			lowTime[u] = min( lowTime[u], visitTime[v]);
		}
	}
}
