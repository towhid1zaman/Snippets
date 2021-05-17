namespace Number_Theory{
    //GCD LCM
    ll gcd(ll a,ll b){
        return b ? gcd(b,a%b) : a;
    }
    ll lcm(ll a, ll b){
        return a/ gcd(a,b)*b;
    }

    //Check Prime
    bool isprime(ll n) { 
        if (n <= 1) return false; 
        if (n <= 3) return true; 
        if (n % 2 == 0 || n % 3 == 0) return false; 
        for (ll i = 5; i * i <= n; i += 6){ 
            if (n % i == 0 || n % (i+2) == 0){
                return false;
            } 
        }
        return true; 
    }

    //sieve, before use it call generate function
    bool prime[15000105]; 
    void sieve(int n) { 
      for (ll i = 0; i <= n; i++) prime[i] = 1;
      for (ll p = 2; p * p <= n; p++) { 
        if (prime[p] == true) { 
          for (ll i = p * p; i <= n; i += p) 
            prime[i] = false; 
        } 
      } 
      prime[1] = prime[0] = 0;
    }

    std::vector<ll>primelist;
    bool prime_generated = 0;

    void GenPrimes(int n){
        prime_generated = 1;
        sieve(n+1);
        for(ll i = 2; i<=n; i++){
            if (prime[i]) primelist.push_back(i);
        }
    }
    // prime factors
    std::vector<ll>factors(ll n) {
    if (!prime_generated) {
        cerr << "Call GenPrimes(int n) first" << endl;
        exit(1);
    }
    std::vector<ll> facs;
        for(ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
            if (n % primelist[i] == 0) {
              while (n % primelist[i] == 0) {
              n /= primelist[i];
              facs.push_back(primelist[i]);
              }
            }
        }
        if (n > 1) {
            facs.push_back(n);
        }
        sort(facs.begin(), facs.end());
        return facs;
    }

    //smallest prime factor
    ll lp[10000005];
    void Smallest_prime_factor(){
        fill(lp, lp+10000005, 0);
        for(ll i=2;i<=10000000;i++){
            if(lp[i]==0)
            for(ll j=i*i;j<=10000000;j+=i){
                if(lp[j]==0)
                lp[j]=i;
            }
            if(lp[i]==0)lp[i]=i;
        }
    }

    // Divisor count sieve
    ll Divisors[10000005];
    void divisor_count(){
        for(ll i = 2; i<10000005; i++){
            if(Divisors[i])continue;
            for(ll j = i; j<10000005; j+=i){
                Divisors[j]++;
            }
        }
    }

    //DivisorCount using primefactorization
    ll divisor(ll n){
        if(!prime_generated){
            cerr << "Call GenPrimes(int n) first" << endl;
            exit(1);
        }
        ll ans = 1;
        for(ll i = 0; i<primelist.size() and primelist[i]*primelist[i]<=n; i++){
            if(n%primelist[i]==0){
                ll cnt = 0;
                while(n%primelist[i]==0){
                    n/=primelist[i];
                    cnt++;
                }
                ans*=(cnt+1);
            }
        }
        if(n!=1)ans*=2;
        return ans;
    }
    //All divisors of a number
    std::vector<ll>getdivs(ll n){
      std::vector<ll>divs;
        for(ll i = 1; i * i <= n; i++) {
          if (n % i == 0) {
            divs.push_back(i);
            if(i != (n/i))divs.push_back(n/i);
          }
      }
      sort(divs.begin(), divs.end());
      return divs;
    }

}using namespace Number_Theory;
