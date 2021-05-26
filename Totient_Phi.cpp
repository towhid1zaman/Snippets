
namespace Totient{
    //count of how many number from 1 to n are coprime(having gcd value 1) to n
    //Notmal Totient calculations
    ll phi(ll n) {
        ll result = n;
        for (ll p = 2; p * p <= n; p++)
            if (n % p == 0) {
                result = result / p * (p - 1);

                do {
                    n /= p;
                } while (n % p == 0);
            }

        if (n > 1)
            result = result / n * (n - 1);

        return result;
    }
    //Euler Totient Sieve O(n log log n)
    ll phi_store[maxn];
    void phiGen(){
        for(int p = 2; p<=maxn; p++){
            if(!phi_store[p]){
                phi_store[p] = p-1;
                for(int i=2*p; i<=maxn; i+=p){
                    if(!phi_store[i])phi_store[i]=i;
                    phi_store[i]/=p;
                    phi_store[i] *=(p-1);
                }
            }
        }
        //for range a to b
        /*
        for(int i = 2; i < maxn;i++){
            phi_store[i]*=phi_store[i];
            phi_store[i]+=phi_store[i-1];
        }
        */
    }
}using namespace Totient;
