//smallest prime factor of a number
int p[10000005];
void sieve(){
    for(ll i=2;i<=10000000;i++){
        if(p[i]==0)
        for(ll j=i*i;j<=10000000;j+=i){
            if(p[j]==0)
            p[j]=i;
        }
    }
}
//or
ll SFact(ll n) { 
    if (n % 2 == 0)return 2; 
    for (ll i = 3; i * i <= n; i += 2) { 
        if (n % i == 0) 
            return i; 
    }
    return n; 
}
