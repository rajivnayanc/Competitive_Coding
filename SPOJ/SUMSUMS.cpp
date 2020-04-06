#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 98765431;
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

ll powll(ll x,ll y){
    ll result = 1;
    while(y>0){
        if(y&1) result = (result*x)%MOD;
        x = (x*x)%MOD;
        y/=2;
    }
    return result;
}
int main(){
	FIO
	ll N,T;cin>>N>>T;
    vector<ll>C(N);
    inp(C,N);
    ll sum = 0;
    for(ll i =0;i<N;i++){
        C[i] = C[i]%MOD;
        sum = (sum%MOD + C[i]%MOD)%MOD;
        sum = (sum+MOD)%MOD;
        
    }
    
    ll f = powll(N-1,T);
    f = (f+ ((T%2==1)?1:-1))%MOD;
    f = (f * powll(N,MOD-2))%MOD;
    f = (f*sum)%MOD;

    for(ll i =0;i<N;i++){
        ll temp = f + ((T&1)?-C[i]:C[i]);
        temp = (temp+MOD)%MOD;
        cout<<temp<<"\n";
    }
	return 0;
}