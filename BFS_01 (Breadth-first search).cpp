int n, m;
std::vector<pair<int,int>>adj[maxn];
std::vector<int>dist;

void bfs_01(int s){
	dist.resize(n+1,1e9);
	deque<int>q;
	q.push_back(s);
	dist[s] = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop_front();
		for(auto p : adj[u]){
			int v = p.first;
			int c = p.second;

			if(dist[v] > dist[u] + c){
				dist[v] = dist[u] + c;
				if(c==1)q.push_back(v);
				else q.push_front(v);
			}
		}
	}
}
