ll D[maxn];
void d(){
    for(ll i = 2; i<maxn; i++){
        if(D[i])continue;
        for(ll j = i; j<maxn; j+=i){
            D[j]++;
        }
    }
}
