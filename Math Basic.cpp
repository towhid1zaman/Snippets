namespace Math_Basic{
    template <class T> T abs(T x){
        return x > 0 ? x : -x;
    }
    template <class T> T sqr(T x){
        return x * x;
    }
    ll Ceil(ll n, ll m){
        return (n+m-1)/m;
    }
    ll bigpow(ll a, ll e) {
        ll ret = 1LL; ll aa = (ll)a;
        while (e) {
            if (e&1) {
                ret *= aa;
                e--;
            }
            aa *= aa;e /= 2;
        }
        return ret;
    }   
}using namespace Math_Basic;
