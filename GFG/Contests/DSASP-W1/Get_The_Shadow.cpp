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

int main(){
	FIO
	ll T;
	cin >> T;
	while (T--){
		ll N;
        cin>>N;
        ll arr[N];
        inp(arr,N)

        ll freq[N+1];
        memset(freq,0,sizeof(freq));

        for(ll i =0;i<N;i++){
            freq[arr[i]]++;
        }
        int a,b;
        for(ll i = 1;i<=N;i++){
            if(freq[i]==0){
                a = i;
            }
            if(freq[i]>=2){
                b=i;
            }
        }
        cout<<b<<" "<<a<<"\n";

	}
	return 0;
}