#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 1e9+7;
typedef long long int ll;
const ll MAX = 2e6;
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

ll inverse2(ll m1, ll p1){
	ll i = 1;
	while(1){
	if((m1*i) % p1 == 1)
		return i;
	i++;
 	}
}

ll gcdExtended(ll a, ll b, ll *x, ll *y) { 
    if (a == 0){ 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
} 
  
ll modInverse(ll a, ll m) { 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        return -1; 
    else{ 
        ll res = (x%m + m) % m; 
        return res; 
    } 
}
  
long long int powll(ll x, ll y, ll mod){
    
    ll result = 1;
    while(y>0){
        if(y&1) result = (result*x)%mod;
        x = (x*x)%mod;
        y/=2;
    }
    return result;
}
ll mul(ll a, ll b, ll mod){
    if (mod <= 1000000009) return (a%mod * b%mod) % mod;
 
    long long int res = 0;
    while (a > 0) {
        if (a & 1) {
            res += b;
            if (res >= mod) res -= mod;
        }
        a >>= 1;
        b <<= 1;
        if (b >= mod) b -= mod;
    }
    return res;
}

ll add(ll a, ll b,ll mod){
    ll temp = (a%mod + b%mod)%mod;
    if(temp<0) 
        temp = (temp+mod)%mod;
    return temp;
}

int main(){
	FIO
	ll T;
	cin >> T;
	while (T--){
		ll N,P;
		cin>>N>>P;
		if(N>=P){
			cout<<"0\n";
			continue;
		}
		ll temp = 1;
		for(ll i = (N+1);i<=(P-1);i++){
			temp = mul(temp,i,P);
		}
		ll result = mul((P-1),modInverse(temp,P),P);
		cout<<result<<"\n";
	}
	return 0;
}