vll prime;
bitset<10000010>bs;

void sieve(){
        bs.set();
        prime.pb(2LL);
        for(ll i = 3; i<=10000000; i+=2){
            if(bs[i]){
                prime.pb(i);
                for(ll j = i*i; j<=10000000; j+=i+i){
                    bs[j] = 0;
                }
            }
        }
}
