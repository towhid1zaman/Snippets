ll derangements(ll n){
    std::vector<ll>d(n+1, 0);
    d[2] = 1ll;
    for(int i = 3; i<=n; i++){
        d[i] = (((d[i-1]+d[i-2])%mod)*(i-1))%mod;
    }
    return d[n];
}
ll Choose(ll n , ll k){
    if(k == 0)
        return 1;
    ll res = n;
    for(int i = 1 ; i < k ; ++i)
        res *= (n-i);
    for(int i = 1 ; i <= k ; ++i)
        res = res / i;
    return res;
}
