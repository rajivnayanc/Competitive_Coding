// A1.cpp


// Rajiv Nayan Choubey
// @rajivnayanc | @rajivnayanch
// August 17, 2020  09:36:28

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

void add_next(vector<ll> & arr, ll a, ll b, ll c, ll d, ll i, ll k){
    if(i>=k){
        ll next_ = big_ModMul(a, arr[i-2],d);
        next_ = big_ModAdd(next_,big_ModMul(b, arr[i-1],d),d);
        next_ = big_ModAdd(next_,c,d);
        arr.push_back(next_+1);
    }
}

void solve(ll t){
    ll n, k ,w; cin>>n>>k>>w;
    vector<ll> L(k); inp(L,k)
    ll Al, Bl, Cl, Dl; cin>>Al>>Bl>>Cl>>Dl;

    vector<ll> H(k); inp(H,k)
    ll Ah, Bh, Ch, Dh; cin>>Ah>>Bh>>Ch>>Dh;
    fr(n){
        add_next(L, Al, Bl, Cl, Dl, i, k);
        add_next(H, Ah, Bh, Ch, Dh, i, k);
    }

    vector<ll> P;

    fr(n){
        ll curr = 2*(H[i]+w);
        if(i==0){
            P.push_back(curr);
            continue;
        }
        if((L[i-1]+w)>=L[i]){
            ll diff, neg, ind;
            if(H[i]<=H[i-1]){
                diff = 2*abs(L[i-1]+w-L[i]);
                neg = 2*min(H[i-1],H[i]);
                ind = i-1;
            }else{
                ll z = i-1;
                ll max_H = H[i-1];
                ind = i-1;
                while(z>=0 and L[z]+w>=L[i]){
                        if(H[z]>max_H){
                            ind = z;
                            max_H = H[z];
                        }
                        z-=1;
                }
                diff = 2*abs(L[ind]+w-L[i]);
                neg = 2*min(H[ind],H[i]);
            }
            P.push_back(big_ModAdd(P[ind]-diff-neg,curr,MOD));
        }else{
            P.push_back(big_ModAdd(P[i-1],curr,MOD));
        }
    }
    ll answer=1;
    for(auto p:P){
        answer= big_ModMul(answer,p,MOD);
    }
    cout<<"Case #"<<t<<": "<<answer<<"\n";

}
int main(){
#ifndef ONLINE_JUDGE
    freopen("perimetric_chapter_1_input.txt", "r", stdin);
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