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


void count(ll N, ll &result){
    if(N==1){
        return;
    }
    if(N%2==0){
        result++;
        return count(N/2,result);
    }
    if(N==3){
        result++;
        return count(N-1,result);
    } 
    if(((N+1)/2)%2==0){
        result++;
        return count(N+1,result);
    }else{
        result++;
        return count(N-1,result);
    }
}

int main(){
	// FIO
	ll T;
	cin >> T;
	while (T--){
		ll N;
        cin>>N;
        ll result = 0;
        count(N,result);
        cout<<result<<"\n";
	}
	return 0;
}