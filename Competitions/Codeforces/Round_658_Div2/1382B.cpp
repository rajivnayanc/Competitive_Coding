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
    ll n; cin>>n;
    ll arr[n];
    inp(arr,n)
    bool curr_play_first = true;
    ll curr_ind = 0;
    ll one_count = 0;
    for(ll i =0;i<n;i++){
        if(arr[i]==1) one_count++;
        else break;
    }
    if(one_count==n){
        curr_play_first=one_count%2==1;
    }else{
        curr_play_first=one_count%2==0;
    }
    if(curr_play_first) cout<<"First\n";
    else cout<<"Second\n";
}	
int main(){
	// FIO
	ll T;
	cin >> T;
	while (T--){
		solve();
	}
	return 0;
}