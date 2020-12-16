//p = position
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define minv(a)    (*min_element((a).begin(), (a).end()))
#define maxv(a)    (*max_element((a).begin(), (a).end()))
#define minp(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxp(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowp(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppp(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
