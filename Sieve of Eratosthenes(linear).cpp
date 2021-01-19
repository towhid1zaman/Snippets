vector<int> primes;
bool isp[maxn]; 
void sieve() {//true means prime
    fill(isp+2, isp+maxn, 1);
    for (int i=2; i<maxn; i++)
        if (isp[i]) {
            for (int j=2*i; j<maxn; j+=i)
                isp[j] =  false;
            primes.push_back(i);
        }
}

//another
vector<int> smallest_factor;
vector<bool> isp;
vector<int> primes;
void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    isp.assign(maximum + 1, true);
    isp[0] = isp[1] = false;
    primes = {};
 
    for (int p = 2; p <= maximum; p++)
        if (isp[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
 
            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (isp[i]) {
                    isp[i] = false;
                    smallest_factor[i] = p;
                }
        }
}
 
