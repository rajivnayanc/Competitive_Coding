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
void solve(){
	ll n,m; cin>>n>>m;
    ll A[n], B[m];
    inp(A,n)
    inp(B,m)
    bool flag=false;
    ll answer =0;
    for(ll i =0;i<n;i++){
        for(ll j =0;j<m;j++){
            if(A[i]==B[j]){
                answer=A[i];
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    if(flag){
        cout<<"YES\n1 "<<answer<<"\n";
    }else{
        cout<<"NO\n";
    }

}	
int main(){
	FIO
	ll T;
	cin >> T;
	while (T--){
		solve();
	}
	return 0;
}