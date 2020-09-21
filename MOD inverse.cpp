ll bigmod(ll a, ll e, ll m) {
	ll ret = 1LL;
	ll aa = (ll)a;
	while (e) {
		if (e&1) {
			ret *= aa;
			if (ret > m)
				ret %= m;
			e--;
		}
		aa *= aa;
		e /= 2;
		if (aa > m)
			aa %= m;
	}
	return ret;
}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime
