int lowTime[maxn], visitTime[maxn], vis[maxn], d, n, m;
vi adj[maxn];
set<pii>st;

void RESET(){
	for(int i = 0; i<=n+5; i++){
		adj[i].clear();
		visitTime[i] = 0;
		lowTime[i] = 0;
		vis[i] = 0;
	}
	st.clear();
}

void dfs(int v, int p=-1){
	vis[v] = 1;
	lowTime[v] = visitTime[v] = d++;
	int cnt = 0;
	for(auto to: adj[v]){
		if(to==p)continue;
		if(vis[to]){
			//back edge
			lowTime[v] = min( lowTime[v], visitTime[to]);
		}
		else{
			dfs(to, v);
			lowTime[v] = min(lowTime[v], lowTime[to]);
			if(lowTime[to] > visitTime[v]){
				st.insert({min(v,to), max(v,to)});
			}
		}
	}
}
