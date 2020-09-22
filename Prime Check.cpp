//check prime
bool isprime(ll n){
    if(n==2)return true;
    if(n<2 or n%2==0)return false;
    for(ll p = 3; p*p<=n;p+=2){
        if(n%p==0){
            return false;
        }
    }
    return true;
}
