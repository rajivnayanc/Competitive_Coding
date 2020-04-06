#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;
#define FIO                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define inp(arr, n)            \
	for (ll i = 0; i < n; i++) \
		cin >> arr[i];
#define fr(n) for (ll i = 0; i < n; i++)
#define frk(i, n) for (ll i = 0; i < n; i++)
#define frs(a, b) for (ll i = a; i <= b, i++)
#define frn(a, b) for (ll i = a; i >= b, i--)
#define sumarray(arr, n, sum)  \
	for (ll i = 0; i < n; i++) \
		sum += arr[i];
ll NcR(ll N,ll R){
    if(R>N/2){
        R = N-R;
    }
    ll result = 1;
    for(ll i =1;i<=R;i++){
        result *=N;
        result/=i;
        N--;
    }
    return result;
}		
int main(){
	FIO
	ll T;
	cin >> T;
	while (T--){
		ll N,K; cin>>N>>K;
        cout<<NcR(N-1,K-1)<<endl;
	}
	return 0;
}