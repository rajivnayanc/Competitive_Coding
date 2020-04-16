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

int main(){
	FIO
	ll N;
    cin>>N;
    ll S[N];
    inp(S,N)
    ll dp[32];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<N;i++){
        ll safe = S[i];
        while(safe){
            ll p = safe&(-safe);
            safe=safe-p;
            ll pos = log2(p);
            dp[pos] = (dp[pos]+1)%3;
        }
    }
    ll answer = 0;
    for(ll i=0;i<=31;i++)
        answer+=dp[i]*power(2,i);
    
    cout<<answer;
	return 0;
}