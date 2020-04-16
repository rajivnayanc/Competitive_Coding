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

ll power(ll x,ll y){
    ll res = 1;
    while(y){
        if(y&1) res = res*x;
        x*=x;
        y>>=1;
    }
    return res;
}
bool isSetBit(ll N, ll pos){
    ll denom = power(2,pos);
    N/=denom;
    return N&1;
}
int main(){
	FIO
	ll N;
    cin>>N;
    ll S[N];
    ll xr = 0;
    for(ll i=0;i<N;i++){
        cin>>S[i];
        xr^=S[i];
    }
    ll pos = log2(xr&(-xr));
    ll temp =0;
    for(ll i =0;i<N;i++){
        if(isSetBit(S[i],pos))
            temp^=S[i];
    }
    ll arr[] = {temp,xr^temp};
    sort(arr,arr+2);
    cout<<arr[0]<<" "<<arr[1];
        
	return 0;
}