#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MAX = 2e6;
const ll MOD = 1e9+7;

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
    ll res = (a*b)%MOD;
    if(res<0)
        res = (res+MOD)%MOD;
    return res;
}

ll add(ll a, ll b){
    ll temp = (a%MOD + b%MOD)%MOD;
    if(temp<0) 
        temp = (temp+MOD)%MOD;
    return temp;
}

int main(){
	FIO
    ll x;cin>>x;
    ll A[x];
    inp(A,x)
    ll product =1;
    for(ll i=0;i<x;i++){
        product = (product*((A[i]+1)%MOD))%MOD;
        if(product<0)
            product = (product+MOD)%MOD;
    }
    ll result = 1;
    for(ll i =0;i<x;i++){
        ll temp = mul(A[i],product);
        temp = mul(temp,powll(2,MOD-2));
        result = mul(result,add(temp,1));
    }
    cout<<result;
	return 0;
}
