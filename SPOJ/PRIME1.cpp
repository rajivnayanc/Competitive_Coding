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
vector<int>prime;
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
    for(int i=0;i<=MAX;i++){
        if(primes[i]){
            prime.push_back(i);
        }
    }
}	
int main(){
	FIO
	sieve();
    int L = prime.size();
    ll T;cin>>T;
    while(T--){
        ll m,n;cin>>m>>n;
        bool pp[n-m+2];
        memset(pp,true,sizeof(pp));

        for(int i =0;i<L;i++){
            ll current_prime = prime[i];

            if((current_prime*current_prime) <= n){
                ll low = floor(m/current_prime)*current_prime;
                if(low<m) low+=current_prime;
                for(ll j =low;j<=n;j+=current_prime){
                    if(j==current_prime)continue;
                    pp[j-m]=false;
                }
            }

        }

        for(ll j =m;j<=n;j++){
            if(j==1) continue;
            if(pp[j-m]==true){
                cout<<j<<"\n";
            }
        }
        cout<<"\n";
    }

	return 0;
}