#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MAX = 2e6;
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
int primes[MAX+1];
void sieve(){
    memset(primes,1,sizeof(primes));
    primes[0]=primes[1]=0;
    for(int i =2;i*i<=MAX;i++){
        if(primes[i]){
            for(int j=i*i;j<=MAX;j+=i){
                primes[j]=0;
            }
        }
    }
}	
int main(){
	FIO
	sieve();
    ll N;cin>>N;
    ll arr[N];
    inp(arr,N)
    for(ll i=0;i<N;i++){
        double t1 = sqrt(arr[i]);
        int t2 = (int)t1;
        if(t1==t2){
            if(primes[t2]){
                cout<<"YES\n";
            }else cout<<"NO\n";
        }else cout<<"NO\n";
    }
	return 0;
}