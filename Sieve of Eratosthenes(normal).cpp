//quick sieve
ll chek[maxn];
bool checkprime[maxn + 5];
vll prime;
void sieve() {///true means prime
	fill(checkprime,1);
    prime.push_back(2);
    checkprime[0]=0;
    checkprime[1]=0;
    for(ll i = 4; i<=maxn; i+=2)checkprime[i] = 0;
    for (ll i = 3; i <= maxn; i += 2) {
        if (checkprime[i]) {
            prime.push_back(i);
            for (ll j = i * i; j <= maxn; j += (i + i))
                checkprime[j] = 0;
        }
    }
    //interval
    chek[0]=0;
    for(int i = 1; i<=maxn; i++){
    	chek[i] = chek[i-1] + checkprime[i-1];
    }

}
