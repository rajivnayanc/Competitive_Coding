#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 1e9;
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

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B){
    ll R1 = A.size();
    ll C1 = A[0].size();
    
    ll R2 = B.size();
    ll C2 = B[0].size();

    vector<vector<ll>> result(R1,vector<ll>(C2,0));
    for(ll i =0;i<R1;i++){
        for(ll j =0;j<C2;j++){
            ll sum = 0;
            for(ll k = 1;k<R2;k++){
                sum = (sum+(A[i][k]*B[k][j])%MOD)%MOD;
            }
            result[i][j] = sum%MOD;
        }
    }
    return result;
}

vector<vector<ll>> pow(vector<vector<ll>> A,ll y){
    ll R = A.size();
    ll C = A[0].size();
    vector<vector<ll>> result(R,vector<ll>(C,0));
    for(ll i =0;i<R;i++)
        result[i][i]=1;

    while(y>0){
        if(y&1)
            result = multiply(result,A);
        
        A = multiply(A,A);
        y /=2;
    }
    
    return result;
}

ll compute(vector<ll> B, vector<ll> C, ll N, ll K){

    if(N<=K){
        return B[N-1];
    }

    vector<ll> F1(K+1);
    for(ll i =1;i<=K;i++){
        F1[i]=B[i-1];
    }
    vector<vector<ll>> T(K+1,vector<ll>(K+1));

    for(ll i =1;i<=K;i++){
        for(ll j =1;j<=K;j++){
            if(i<K){
                if(j==(i+1))
                    T[i][j]=1;
                else T[i][j]=0;
            }else{
                T[i][j]=C[K-j];
            }
        }
    }
    
    ll result = 0;
    T = pow(T,N-1);

    for(ll i =1;i<=K;i++){
        result=(result+(T[1][i]*F1[i])%MOD)%MOD;
    }

    return result%MOD;

}

int main(){
	FIO
	ll T;
	cin >> T;
	while (T--){
		ll K;cin>>K;
        vector<ll>B(K),C(K);
        inp(B,K)
        inp(C,K)
        ll N; cin>>N;
        cout<<compute(B,C,N,K)<<"\n";        
	}
	return 0;
}