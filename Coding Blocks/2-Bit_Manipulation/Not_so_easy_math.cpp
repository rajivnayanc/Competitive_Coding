#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FIO                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define inp(arr, n)            \
	for (ll i = 0; i < n; i++) \
		cin >> arr[i];
#define fr(n) for (ll i = 0; i < n; i++)
#define frk(i, n) for (ll i = 0; i < n; i++)
#define frs(a, b) for (ll i = a; i <= b; i++)
#define frn(a, b) for (ll i = a; i >= b; i--)
#define sumarray(arr, n, sum)  \
	for (ll i = 0; i < n; i++) \
		sum += arr[i];
       
ll countSetBits(ll n){
    ll ans = 0;
    while(n){
        n = n&(n-1);
        ans++;
    }
    return ans;
}
ll power(ll x,ll y){
    ll res = 1;
    while(y){
        if(y&1) res = res*x;
        x*=x;
        y>>=1;
    }
    return res;
}
void solve(ll primes[], ll no_of_primes, ll N){
    ll LAST = power(2,no_of_primes)-1;
    ll ans = 0;
    for(ll i=1;i<=LAST;i++){
        ll safe = i;
        ll count = 0;
        ll product = 1;
        while(safe){
            ll p = safe&(-safe);
            ll pos = log2(p);
            count++;
            safe = safe-p;
            product*=primes[pos];
        }
        ll temp = N/product;
        if(count&1){
            ans+=temp;
        }else{
            ans-=temp;
        }
    }
    cout<<ans<<"\n";
}
int main(){
	FIO
    ll primes[]={2,3,5,7,11,13,17,19};
    ll no_of_primes = sizeof(primes)/sizeof(primes[0]); 
	ll T;
	cin >> T;
	while (T--){
		ll N;
        cin>>N;
        solve(primes,no_of_primes,N);
	}
	return 0;
}