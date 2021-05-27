namespace prime_factorization{
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
}using namespace prime_factorization;
