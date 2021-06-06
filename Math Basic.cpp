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
    ll gcd(ll a,ll b){
        return b ? gcd(b,a%b) : a;
    }
    ll lcm(ll a, ll b){
        return a/ gcd(a,b)*b;
    }
    ll gcdExtended(ll a,ll b,ll &x,ll &y){
        if(b==0){
            x=1ll,y=0ll;
            return a;
        }
        ll g = gcdExtended(b,a%b,y,x);
        y-=a/b*x;
        return g;
    }
    ll bigpow(ll a, ll e){
        ll ret = 1LL; ll aa = (ll)a;
        while (e){
            if (e&1) {
                ret *= aa;
                e--;
            }
            aa *= aa;e /= 2;
        }
        return ret;
    }   
}using namespace Math_Basic;
