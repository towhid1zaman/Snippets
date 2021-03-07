//smallest prime factor of a number
ll lp[10000005];
void sieve(){
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
//or
ll SFact(ll n) { 
    if (n % 2 == 0)return 2; 
    for (ll i = 3; i * i <= n; i += 2) { 
        if (n % i == 0) 
            return i; 
    }
    return n; 
}
