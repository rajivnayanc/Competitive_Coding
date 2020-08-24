// MIN QUERY I.cpp


// Rajiv Nayan Choubey
// @rajivnayanc | @rajivnayanch
// August 24, 2020  15:39:10

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
const ll MAX = 1e6;
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
ll arr[MAX+1];

class SegmentTree {
    ll vect[4*MAX+1];
    public:
    void build(ll idx, ll start, ll end){
        if(start==end){
            vect[idx]=arr[start];
        }else{
            ll mid = (start+end)/2;
            build(2*idx+1,start,mid);
            build(2*idx+2,mid+1,end);

            ll l_i = 2*idx+1, r_i=2*idx+2;
            vect[idx] = min(vect[l_i],vect[r_i]);
        }
    }
    void update(ll idx, ll i, ll val,ll start, ll end){
        if(i<start || i>end) return;
        if(start==end){
            vect[idx]=val;
        }else{
            ll mid = (start+end)/2;
            update(2*idx+1,i,val,start,mid);
            update(2*idx+2,i,val,mid+1,end);

            ll l_i = 2*idx+1, r_i=2*idx+2;
            vect[idx] = min(vect[l_i],vect[r_i]);
        }
    }
    ll query(ll idx, ll ss, ll se, ll qs, ll qe){
        if(qs>se || qe<ss) return INT_MAX;
        if(qs<=ss && qe>=se){
            return vect[idx];
        }

        ll mid = (se+ss)/2;
        ll leftQuery = query(2*idx+1,ss,mid,qs,qe);
        ll rightQuery = query(2*idx+2,mid+1,se,qs,qe);

        return min(leftQuery,rightQuery);
    }
};

void solve(){
    ll N,Q;cin>>N>>Q;
    inp(arr,N)
    SegmentTree * segTree = new SegmentTree;
    segTree->build(0,0,N-1);
    ll a,b,c;
    while(Q--){
        cin>>a>>b>>c;
        if(a==1){
            cout<<segTree->query(0,0,N-1,b-1,c-1)<<"\n";
        }else{
            segTree->update(0,b-1,c,0,N-1);
        }
    }

}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FIO
    ll T;
    // cin >> T;
    T=1;
    while (T--){
        solve();
    }
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