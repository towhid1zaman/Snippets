//prime factorization
vector<pair<ll,ll>>factorize(ll a){
    vector<pair<ll,ll> > pf;
    for (ll i = 2; i * i <= a; ++i) {
        if (a % i) continue;
        pf.emplace_back(i, 0);
        while (a % i == 0) {
            ++pf.back().second;
            a /= i;
        }
    }
    if (a > 1) {
        pf.emplace_back(a, 1);
    }
    return pf;
}
