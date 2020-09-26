std::vector<int>adj[maxn];
bool vis[maxn];
int dist[maxn];
int par[maxn];

void RESET(){
	for(int i = 0; i<maxn; i++){
		vis[i] = 0;
		dist[i] = 0;
		par[i] = 0;
		adj[i].clear();
	}
}

void bfs(int source){
	queue<int>q;
	q.push(source);
	vis[source] = 1, dist[source] = 0, par[source] = -1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v:adj[u]){
			if(vis[v])continue;
			q.push(v);
			vis[v] = 1, dist[v] = dist[u] + 1, par[v] = u;
		}
	}
}
//first call bfs()
void path_print(int destination){
	std::vector<int>path;
	int u = destination;
	while(u!=-1){
		path.push_back(u);
		u = par[u];
	}
	reverse(path.begin(), path.end());
	for(auto node : path){
		cout << node <<' ';
	}
	cout << endl;
}
