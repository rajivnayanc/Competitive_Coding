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

ll pw(ll x, ll y, ll p){
    ll res=1;
    while(y>0) {
       if(y%2==1) res=(res*x)%p;
       x=(x*x)%p;
       y/=2;
    }
    return res%p;
}


int main(){
	FIO
    ll prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    ll nprime = 25;
    ll tree[26][100002];
    vector<pair<ll,ll>> primeCount[102];
	memset(tree,0,sizeof(tree));
    for(ll i =2;i<=100;i++){
        ll temp = i;
        for(ll j =0;j<nprime;j++){
            ll count = 0;
            while(temp%prime[j]==0){
                count++;
                temp/=prime[j];
            }
            if(count){
                primeCount[i].push_back(make_pair(j,count));
            }
            if(temp==1) break;
        }
    }
    ll N;
	cin >> N;
    ll A[N];
    inp(A,N)
    for(ll i =1;i<=N;i++){
        ll a= A[i-1];
        ll L = primeCount[a].size();
        for(ll j=0;j<L;j++){
            tree[primeCount[a][j].first][i] += primeCount[a][j].second;
        }

        for(ll j =0;j<nprime;j++){
            tree[j][i]+=tree[j][i-1];
        }
    }


    ll T;cin>>T;
	while (T--){
		ll L,R,p;cin>>L>>R>>p;
		ll result=1;
        for(ll j =0;j<nprime;j++){
            ll t = tree[j][R]-tree[j][L-1];
            // if(t)
                result = (result*pw(prime[j],t,p))%p;
            if(result==0){
                break;
            }
        }
        cout<<result<<"\n";
	}
	return 0;
}
