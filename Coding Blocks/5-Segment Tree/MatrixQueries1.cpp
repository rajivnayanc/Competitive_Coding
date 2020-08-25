// FibonnaciWithGCD.cpp


// Rajiv Nayan Choubey
// @rajivnayanc | @rajivnayanch
// August 25, 2020  09:41:55

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
const ll MAX = 2e5;
const ll MOD = 1e9+7;

#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define inp(arr, n) for (ll i = 0; i < n; i++) cin >> arr[i];
#define fr(n) for (ll i = 0; i < n; i++)
#define frk(i, n) for (ll i = 0; i < n; i++)
#define frs(a, b) for (ll i = a; i <= b; i++)
#define frn(a, b) for (ll i = a; i >= b; i--)
#define sumarray(arr, n, sum) for (ll i = 0; i < n; i++) sum += arr[i];
#define all(v) v.begin(), v.end()
#define pp(a) pair<a, a>
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
            pbds_set;
ll mod_power(ll,ll,ll);
ll big_ModAdd(ll,ll,ll);
ll big_ModMul(ll,ll,ll);
ll gcdExtended(ll,ll,ll*,ll*);
ll modInverse(ll,ll);
ll gcd(ll,ll);
ll countSetBits(ll);

typedef struct matrix{
    ll data[2][2];
} Matrix;

Matrix matrices[MAX+1];

Matrix matMul(Matrix A, Matrix B, ll mod){
    ll R1 = 2;
    ll C1R2 = 2;
    ll C2 =  2;

    ll result[2][2];
    ll sum;
    for(ll i =0;i<R1;i++){
        for(ll j=0;j<C2;j++){
            sum = 0;
            for(ll k=0;k<C1R2;k++){
                sum = (sum+(A.data[i][k]*B.data[k][j])%mod)%mod;
            }
            result[i][j]=sum%mod;
        }
    }
    Matrix res;
    res.data[0][0]=result[0][0];
    res.data[0][1]=result[0][1];
    res.data[1][1]=result[1][1];
    res.data[1][0]=result[1][0];
    return res;
}

class SegmentTree {
    Matrix vect[4*MAX+1];
    public:
    void build(ll idx, ll start, ll end, ll mod){
        if(start==end){
            vect[idx]=matrices[start];
        }else{
            ll mid = (start+end)/2;
            build(2*idx+1,start,mid, mod);
            build(2*idx+2,mid+1,end, mod);

            ll l_i = 2*idx+1, r_i=2*idx+2;
            vect[idx] = matMul(vect[l_i],vect[r_i], mod);
        }
    }
    Matrix query(ll idx, ll ss, ll se, ll qs, ll qe, ll R){
        if(qs>se || qe<ss){
            Matrix res;
            res.data[0][0]=1;
            res.data[0][1]=0;
            res.data[1][0]=0;
            res.data[1][1]=1;
            return res;
        };
        if(qs<=ss && qe>=se){
            return vect[idx];
        }
        ll mid = (se+ss)/2;
        Matrix leftQuery = query(2*idx+1,ss,mid,qs,qe,R);
        Matrix rightQuery = query(2*idx+2,mid+1,se,qs,qe,R);

        return matMul(leftQuery,rightQuery,R);
    }
};



void solve(){
    ll R, N, Q; cin>>R>>N>>Q;
    for(ll i =0;i<N;i++){
        cin>>matrices[i].data[0][0];
        cin>>matrices[i].data[0][1];
        cin>>matrices[i].data[1][0];
        cin>>matrices[i].data[1][1];
    }
    SegmentTree * segTree = new SegmentTree;
    segTree->build(0,0,N-1,R);
    ll l,r;
    Matrix res;
    while(Q--){
        cin>>l>>r;
        res = segTree->query(0,0,N-1,l-1,r-1,R);
        cout<<res.data[0][0]<<" "<<res.data[0][1]<<"\n";
        cout<<res.data[1][0]<<" "<<res.data[1][1];
        cout<<"\n";
        if(Q!=0)cout<<"\n";
    }


}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FIO
    solve();
    return 0;
}

ll mod_power(ll x, ll y, ll mod){
    if(x==0) return x;
    ll res = 1;
    while(y>0){
        if(y&1) res = (res*x)%mod;
        y>>=1;
        x=(x*x)%mod;
    }
    return res;
}

ll big_ModAdd(ll a, ll b,ll mod){
    ll temp = (a%mod + b%mod)%mod;
    if(temp<0) 
        temp = (temp+mod)%mod;
    return temp;
}

ll big_ModMul(ll a, ll b, ll mod){
    if (mod <= 1000000009) return (a%mod * b%mod) % mod;

    long long int res = 0;
    while (a > 0) {
        if (a & 1) {
            res += b;
            if (res >= mod) res -= mod;
        }
        a >>= 1;
        b <<= 1;
        if (b >= mod) b -= mod;
    }
    return res;
}
ll gcdExtended(ll a, ll b, ll *x, ll *y) { 
    if (a == 0){ 
        *x = 0, *y = 1; 
        return b; 
    } 

    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
} 

ll modInverse(ll a, ll m) { 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        return -1; 
    else{ 
        ll res = (x%m + m) % m; 
        return res; 
    } 
}

ll gcd(ll a, ll b){
    if(a==0) return b;
    return gcd(b%a,a);
}

ll countSetBits(ll n){
    ll ans = 0;
    while(n){
        ll temp = n&(-n);
        //log(temp) = 0 base position of first set bit
        n = n-temp;
        ans++;
    }
    return ans;
}