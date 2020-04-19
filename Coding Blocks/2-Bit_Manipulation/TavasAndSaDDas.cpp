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

ll countDigits(ll N){
    if(N==0) return 1;
    ll ans = 0;
    while(N){
        N/=10;
        ans++;
    }
    return ans;
}
void solve(ll N){
    ll before = 0;
    ll digits = countDigits(N);
    before = power(2,digits)-2;
    ll k = 0;
    ll after = 0;
    while(N){
        ll temp = N%10;
        N/=10;
        after += power(2,k)*((temp==7)?1:0);
        k++;
    }
    cout<<(before+after+1);
}
int main(){
	FIO
    ll N;
    cin>>N;
    solve(N);
	return 0;
}