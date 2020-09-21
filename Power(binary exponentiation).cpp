//binary exponentiation
ll Pow(ll x,ll n){
    ll res = 1;
    while(n>0){
        if(n%2==1){
            res = res*x;
        }
        x = x*x;
        n = n/2;
    }
    return res;
}
