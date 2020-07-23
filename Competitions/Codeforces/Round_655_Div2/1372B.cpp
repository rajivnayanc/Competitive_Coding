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
		
int main(){
	FIO
	ll T;
	cin >> T;
	while (T--){
		ll N; cin>>N;
        // if(N&1){
        bool flag = false;
        for(ll i = 1;i<(ll)sqrt(N);i++){
            if(N%(i+1)==0){
                ll x = N/(i+1);
                cout<<x<<" "<<i*x;
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<1<<" "<<N-1;
        }
        cout<<"\n";
	}
	return 0;
}