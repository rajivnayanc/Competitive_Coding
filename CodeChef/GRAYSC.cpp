#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;
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
	ll N;
    cin>>N;
    ll A[N];
    inp(A,N)

    if(N>=130){
        cout<<"Yes\n";
        return 0;
    }
    for (ll i = 0; i < N; i++){
        for(ll j =i+1;j<N;j++){
            for(ll k = j+1;k<N;k++){
                for(ll l = k+1;l<N;l++){
                    if((A[i]^A[j]^A[k]^A[l])==0){
                        cout<<"Yes\n";
                        return 0;
                    }
                }
            }
        }
    }
    
    cout<<"No";
    return 0;
}