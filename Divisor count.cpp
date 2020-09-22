/*
N=p1^q1 x p2^q2 x p3^q3 x . . . . . . . . x pk^qk
Then the number of divisors: D(N) = (q1+1) x (q2+1) x (q3+1) x. . . . . . . . . x (qk+1)
*/

//quick sieve
bool checkprime[maxn + 5];
vll prime;
void sieve() {///false means prime
    prime.push_back(2);
    checkprime[0]=true;
    checkprime[1]=true;
    for(ll i = 4; i<=maxn; i+=2)checkprime[i] = true;
    for (ll i = 3; i <= maxn; i += 2) {
        if (!checkprime[i]) {
            prime.push_back(i);
            for (ll j = i * i; j <= maxn; j += (i + i))
                checkprime[j] = true;
        }
    }
}
//DivisorCount using primefactorization
void divisor(ll n){
    ll ans = 1;
    for(ll i = 0; i<prime.size() and prime[i]*prime[i]<=n; i++){
        if(n%prime[i]==0){
            ll cnt = 0;
            while(n%prime[i]==0){
                n/=prime[i];
                cnt++;
            }
            ans*=(cnt+1);
        }
    }
    if(n!=1)ans*=2;
    return ans;
}
