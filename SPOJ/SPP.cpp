#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

unsigned long long int MOD;
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
                sum = (sum+(A[i][k]*B[k][j])%MOD+MOD)%MOD;
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
        ll sum = 0;
        for(ll i =0;i<N;i++){
            sum = (sum+B[i])%MOD;
        }
        return sum%MOD;
    }
    vector<ll> F1(K+2);
    F1[1] = B[0];
    // F1[1] = 0;
    for(ll i =2;i<=K+1;i++){
        F1[i]=B[i-2];
    }
    vector<vector<ll>> T(K+2,vector<ll>(K+2));
    T[1][1]=1;
    if(K>=2)
        T[1][3]=1;
    else
    {
        T[1][2]=1;
    }
    


    for(ll i =2;i<K+1;i++){
        T[i][i+1]=1;
    }
    // for(ll i =2;i<=K+1;i++){
    //     T[i-1][i]=1;
    // }
    for (int i = 1; i <= K; i ++) {
        T[K + 1][i + 1] = C[K - i];
    }
    // for(ll i =0;i<=(K+1);i++){
    //     for(ll j =0;j<=(K+1);j++)
    //         cout<<T[i][j]<<" ";
    //     cout<<endl;
    // }
    ll result = 0;
    if(K>=2)
        T = pow(T,N-1);
    else
        T = pow(T,N);
    for(ll i =0;i<=(K+1);i++){
        result=(result%MOD+(T[1][i]*F1[i])%MOD);
        if(result<0){
            result = (result+MOD)%MOD;
        }
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
        ll M,N,P; cin>>M>>N>>P;
        MOD = P;
        if(N<=K){
            ll sum = 0;
            for(ll i =0;i<N;i++){
                sum+=B[i];
            }
        }
        ll l = compute(B,C,M-1,K);
        ll r = compute(B,C,N,K);
        cout<<((r-l + MOD)%MOD)<<"\n";        
	}
	return 0;
}