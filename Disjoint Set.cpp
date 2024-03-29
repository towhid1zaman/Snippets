struct disjoint{
        int fa[maxn];
        int sz[maxn];
        void Build(int n){
            for(int i = 0; i<=n; i++) fa[i]=i, sz[i] = 1;
        }
        int Find(int x){ 
            return x==fa[x]?x:fa[x]=Find(fa[x]);
        }
        void Union(int a, int b){ 
            a = Find(a), b = Find(b);
            if(a==b)return;
            if(sz[a] < sz[b]) swap(a,b);
            fa[b] = a;
            sz[a] += sz[b];
        }
        int Size(int n){
            return sz[n];
        }
}dsu;
