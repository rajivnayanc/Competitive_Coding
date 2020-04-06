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
#define frs(a, b) for (ll i = a; i <= b, i++)
#define frn(a, b) for (ll i = a; i >= b, i--)
#define sumarray(arr, n, sum)  \
	for (ll i = 0; i < n; i++) \
		sum += arr[i];

ll modExp(ll x, ll y, ll p){
    ll res=1;
    while(y>0) {
       if(y%2==1) res=(res*x)%p;
       x=(x*x)%p;
       y/=2;
    }
    return res%p;
}
int main()
{
	FIO
	ll T;
	cin >> T;
	while (T--){
		ll N;cin>>N;
		N++;
		ll maxi = 1e9+7;
        cout<<(ll)(modExp(2,N/2,maxi)+modExp(2,N-N/2,maxi)-2)%(maxi)<<"\n";
	}
	return 0;
}
