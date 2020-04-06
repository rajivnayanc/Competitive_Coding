// Incomplete
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MAX = 2e6;
const ll MOD = 109546051211LL;
const ll MOD2 = 587117;

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

ll powll(ll x,ll y){
    ll result = 1;
    while(y>0){
        if(y&1) result = (result*x)%MOD;
        x = (x*x)%MOD;
        y/=2;
    }
    return result;
}
ll mul(ll a, ll b){
    if (MOD <= 1000000009) return a * b % MOD;
 
    long long int res = 0;
    while (a > 0) {
        if (a & 1) {
            res += b;
            if (res >= MOD) res -= MOD;
        }
        a >>= 1;
        b <<= 1;
        if (b >= MOD) b -= MOD;
    }
    return res;
}

ll add(ll a, ll b){
    ll temp = (a%MOD + b%MOD)%MOD;
    if(temp<0) 
        temp = (temp+MOD)%MOD;
    return temp;
}
ll fact[MAX+1];
void factorial(){
    fact[0]=1;
    for(ll i =1;i<MOD2;i++){
        fact[i]=mul(i,fact[i-1]);
    }
}

int main(){
	FIO
    ll T;cin>>T;
    while(T--){
        ll N;
        cin>>N;
        ll S[N];
        inp(S,N)
        
    }
    return 0;
}
