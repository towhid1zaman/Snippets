//dist calculate lavels, and ways calculate number of ways of same shortest path from source to any other node

std::vector<int>adj[maxn];
bool vis[maxn];
int dist[maxn], par[maxn], ways[maxn];

void RESET(){
	for(int i = 0; i<maxn; i++){
		vis[i] = 0;
		dist[i] = 0;
		par[i] = 0;
		ways[i] = 0;
		adj[i].clear();
	}
}

void bfs(int source){
	queue<int>q;
	q.push(source);
	vis[source] = 1, dist[source] = 0, par[source] = -1;
	ways[source] = 1;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto child:adj[node]){
			if(!vis[child]){
				q.push(child);
				vis[child] = 1, dist[child] = dist[node] + 1, par[child] = node;
				ways[child] += ways[node];
			}
			else{
				if(dist[node]+1 == dist[child]){
					ways[child] += ways[node];
				}
			}
		}
	}
}
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
