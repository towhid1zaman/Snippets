namespace ModOperations{
    inline ll addmod(ll a,ll b){
        return ((a % mod) + (b % mod)) % mod;
    }
    inline ll submod(ll a,ll b){
        return ((a % mod) - (b % mod) + mod) % mod;
    }
    inline ll mulmod(ll a,ll b){
        return ((a % mod) * (b % mod)) % mod;
    }
    inline ll bigmod(ll a, ll e, ll m) {
        ll ret = 1LL;ll aa = (ll)a;
        while (e) {
            if (e&1) {
                ret *= aa;
                if(ret > m)ret %= m;
                e--;
            }
            aa *= aa;e /= 2;
            if(aa > m)aa %= m;
        }
        return ret;
    }
    inline ll invmod(ll base){
	  return bigmod(base,mod-2, mod);
	}
	inline ll divmod(ll a, ll b) {
	  return mulmod(a, invmod(b));
	}
}using namespace ModOperations;
