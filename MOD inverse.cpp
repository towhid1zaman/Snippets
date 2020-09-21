template<typename T> T bigmod(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
