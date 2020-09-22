//segmented sieve
/// first generate prime using seive
vector<ll>prime;
void seive()
{
    bool primes[maxn+1];
    memset(primes,true, sizeof(primes));
    for(ll p = 2; p*p<=maxn;p++)
    {
        ///true means prime
        if(primes[p]==true)
        {
            for(int i = p*p;i<=maxn;i+=p)
            {
                primes[i] = false;
            }
        }
    }
    for(int i = 2; i<=maxn;i++){
            if(primes[i]==true){
                prime.push_back(i);
            }
        }
}
/// range
vector<ll>rPrime;  //final result
void segmented(ll L, ll R)
{
    bool isPrime[L+R-1];
    memset(isPrime,true,sizeof(isPrime));
    if(L==1){
        isPrime[0] = false;
    }
    for(ll i = 0;prime[i]*prime[i]<=R;i++){
        ll curPrime = prime[i];
        ll base = curPrime*curPrime;
        if(base<L)
        {
            base = ((L+curPrime-1)/curPrime)*curPrime;
        }
        for(ll j = base; j<=R;j+=curPrime){
            isPrime[j-L] = false;
        }
    }
    for(int i = 0;i<=R-L;i++)
    {
        if(isPrime[i]==true){
            rPrime.push_back(L+i);
        }
    }
}
