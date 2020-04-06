#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6+5;
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

ll last_occurence[N], dp[N+1];
int main(){
	FIO
	ll n;
    cin>>n;

    ll curr = 0;
    ll sum = 0;
    for(ll i =1;i<=n;i++){
        ll t;cin>>t;
        dp[i] =dp[i-1] +(i-last_occurence[t]);
        last_occurence[t]=i;
        sum+=dp[i];
    }

    double ans = 0.0;
    ans = (1.0*(2*sum -n))/(n*n*1.0);
    cout<<fixed<<setprecision(30)<<ans;

	return 0;
}