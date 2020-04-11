#include <bits/stdc++.h>
#include<stdint.h>
using namespace std;

typedef int64_t ll;
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
int board[1000][1000];
ll countSetBits(ll N){
    int ans =0;
    while(N){
        N = N&(N-1);
        ans++;
    }
    return ans;
}
ll power(ll x,ll y){
    ll res = 1;
    while(y){
        if(y&1) res = res*x;
        x*=x;
        y>>=1;
    }
    return res;
}
void NQueens(ll N,ll &ans,ll DONE=-1,ll rowmask=0,ll rd=0,ll ld=0, ll row=0){
    if(DONE==-1){
        DONE=power(2,N)-1;
    }
    if(rowmask==DONE){
        ans++;
        // for(ll i =0;i<N;i++){
        //     for(ll j=0;j<N;j++){
        //         cout<<board[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return;
    }
    ll safe = DONE &(~(rowmask|rd|ld));
    while(safe){
        ll p = safe&(-safe);
        safe=safe-p;
        ll col = log2(p);
        board[row][col]=1;
        NQueens(N,ans,DONE,(rowmask|p),(rd|p)>>1,(ld|p)<<1,row+1);
        board[row][col]=0;
    }
}
int main(){
	// FIO
    ll T;
    cin>>T;
    while(T--){
        ll N;cin>>N;
        ll ans = 0;
        NQueens(N,ans);
        cout<<"Total Combinations: "<<ans<<endl;
    }
    return 0;
}