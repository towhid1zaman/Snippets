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
