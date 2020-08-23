// A2.cpp


// Rajiv Nayan Choubey
// @rajivnayanc | @rajivnayanch
// August 17, 2020  10:20:34

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
typedef tree<pair<ll,ll>, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
            pbds_set;
ll mod_power(ll,ll,ll);
ll big_ModAdd(ll,ll,ll);
ll big_ModMul(ll,ll,ll);
ll gcdExtended(ll,ll,ll*,ll*);
ll modInverse(ll,ll);
ll gcd(ll,ll);
ll countSetBits(ll);

void add_next(vector<ll> & arr, ll a, ll b, ll c, ll d, ll i, ll k){
    if(i>=k){
        ll next_ = big_ModMul(a, arr[i-2],d);
        next_ = big_ModAdd(next_,big_ModMul(b, arr[i-1],d),d);
        next_ = big_ModAdd(next_,c,d);
        arr.push_back(next_+1);
    }
}

bool doesOverlap(ll x1, ll x2, ll y1, ll y2){
    return x1 <= y2 && y1 <= x2;
}

ll getOverlap(ll x1, ll x2, ll y1, ll y2){
    return min(x2,y2) - max(x1,y1);
}

void solve(ll t){
    ll n, k; cin>>n>>k;
    vector<ll> L(k); inp(L,k)
    ll Al, Bl, Cl, Dl; cin>>Al>>Bl>>Cl>>Dl;
    
    vector<ll> W(k); inp(W,k)
    ll Aw, Bw, Cw, Dw; cin>>Aw>>Bw>>Cw>>Dw;

    vector<ll> H(k); inp(H,k)
    ll Ah, Bh, Ch, Dh; cin>>Ah>>Bh>>Ch>>Dh;
    fr(n){
        add_next(L, Al, Bl, Cl, Dl, i, k);
        add_next(H, Ah, Bh, Ch, Dh, i, k);
        add_next(W, Aw, Bw, Cw, Dw, i, k);
    }

    vector<ll> P;
    set<pp(ll)> intervals;
    intervals.insert({-1,-1});
    intervals.insert({INT_MAX,INT_MAX});
    fr(n){
        ll curr = 2*(H[i]+W[i]);
        if(i==0){
            P.push_back(curr);
            intervals.insert({L[i],L[i]+W[i]});
            continue;
        }
        auto it = prev(intervals.lower_bound({L[i],-1}));
        ll x1 = L[i], x2 = L[i]+W[i];
        if(it->second < x1) it++;
        ll new_x1 = x1;
        ll new_x2 = x2;
        ll sum = curr;
        vector<set<pp(ll)>::iterator> to_delete;
        while(1){
            ll y1 = it->first, y2 = it->second;
            if(doesOverlap(x1,x2,y1,y2)){
                ll overlap = getOverlap(x1,x2,y1,y2);
                sum -= 2*overlap;
                sum -= 2*H[i];
                new_x1 = min(new_x1,y1);
                new_x2 = max(new_x2,y2);
                to_delete.push_back(it);
            }else{
                break;
            }
            it++;
        }
        for(auto it:to_delete){
            intervals.erase(it);
        }
        intervals.insert({new_x1, new_x2});
        P.push_back(big_ModAdd(P[i-1],sum,MOD));
    }
    ll answer=1;
    for(auto p:P){
        answer= big_ModMul(answer,p,MOD);
    }
    cout<<"Case #"<<t<<": "<<answer<<"\n";

}
int main(){
#ifndef ONLINE_JUDGE
    freopen("perimetric_chapter_2_input.txt", "r", stdin);
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FIO
    ll T;
    cin >> T;
    ll Z = T;
    while (T--){
        solve(Z-T);
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