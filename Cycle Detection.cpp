namespace CycleDetection{
    std::vector<int> adj[200000];
    std::vector<int> color; // 0 - not visited,1 = entered for visit,2 = visited
    std::vector<int> parent;
    std::vector<bool> visited;
    int cycle_start, cycle_end;

    bool dfsDirected(int v){
        color[v] = 1;
        for(auto u : adj[v]){
            if(color[u] == 0){
                parent[u] = v;
                if(dfsDirected(u))return true;
            }
            else if(color[u] == 1){
                cycle_end = v;
                cycle_start = u;
                return true;
            }
        }
        color[v] = 2;
        return false;
    }

    bool dfsUndirected(int v, int par){
        visited[v] = 1;
        for(auto u : adj[v]){
            if(u == par)continue;
            if(visited[u] == 1){
                cycle_end =  v;
                cycle_start = u;
                return true;
            }
            parent[u] = v;
            if(dfsUndirected(u, parent[u])){
                return true;
            }
        }
        return false;
    }

    std::vector<int>find_cycle(int n){
        //color.assign(n, 0); // for Directed
        visited.assign(n, false); // for Undirected
        parent.assign(n, -1);
        cycle_start = -1;
        for(int v = 0; v<n; v++){
            //for Directed
            /*
            if(color[v] == 0 and dfsDirected(v)){
                break;
            }
            */
            //for Undirected
            if(visited[v] == 0 and dfsUndirected(v, parent[v])) {
                break;
            }
        }
        std::vector<int> cycle;
        if(cycle_start == -1){
            //cout << "Ascyclic Graph"<<endl; 
            //cout << -1 << endl;
            //cout << "IMPOSSIBLE"<< endl;
            return cycle; // cycle.size() 0 means cycle not found
        }
        else{
            cycle.push_back(cycle_start);
            for(int v = cycle_end; v != cycle_start; v = parent[v]){
                cycle.push_back(v);
            }
            cycle.push_back(cycle_start);
           reverse(cycle.begin(), cycle.end());
           //sort(cycle.begin(), cycle.end());
            return cycle;
        }

    }
 
}using namespace CycleDetection;

//Deirected Example : http://p.ip.fi/S4cX
//Undirected Example : http://p.ip.fi/_-Gn
