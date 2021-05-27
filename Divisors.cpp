namespace divisors{
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
        
    // Divisor count sieve O(n log n)
    ll divCnt[10000005];
    void divisor_count(ll n){
        for(ll i = 1; i <= n; i++){
            for(ll j = i; j <= n; j+=i){
                divCnt[j]++;
            }
        }
    }
    // Divisor sum sieve O(n log n)
    ll divSum[10000005];
    void divisor_sum(ll n){
        for(ll i = 1; i <= n; i++){
            for(ll j = i; j <= n; j+=i){
                divSum[j]+=i;
            }
        }
    }
    //DivisorCount using primefactorization
    ll total_divisors(ll n){
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

    ll sum_0f_divisors(ll n){
      if(!prime_generated){
          cerr << "Call GenPrimes(int n) first" << endl;
          exit(1);
      }
      ll oo = n;
      ll ans = 1;
      for(ll i = 0; i<primelist.size() and (ll)primelist[i]*primelist[i]<=n; i++){
          int cnt = 0;
          ll sum = 1, pw = 1;
          while(n%primelist[i]==0){
              pw*=primelist[i];
              sum+=pw;
              cnt++;
              n/=primelist[i];
          }
          if(cnt>0) ans*=sum;
      }
      if(n>1)ans*=n+1;
      return ans - oo; //less than n
  }
}using namespace divisors;
