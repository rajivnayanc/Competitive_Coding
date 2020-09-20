// BULBS.cpp


// Rajiv Nayan Choubey
// @rajivnayanc | @rajivnayanch
// September 20, 2020  22:16:43

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

void solve(){
    ll N, K; cin>>N>>K;
    string s; cin>>s;
    vector<ll> zeros;
    bool flag = false;
    ll count = 0;
    for(auto S:s){
        if(S=='0') count++;
    }
    if(count==N || count==0){
        cout<<"0\n";return;
    }
    if(K==0){
        cout<<count<<"\n";
        return;
    }
    N = s.length();
    ll left  = 0, right =0;

    for(ll i=0;i<N;i++){
        if(s[i]=='1') break;
        left++;
    }
    for(ll i=N-1;i>=0;i--){
        if(s[i]=='1') break;
        right++;
    }

    count = 0;
    for(ll i=left;i<N-right;i++){
        if(s[i]=='0'){
            count++;
        }else if(count>0){
            zeros.push_back(count);
            count=0;
        }
    }
    if(count>0) zeros.push_back(count);

    sort(zeros.begin(), zeros.end(), greater<ll>());
    vector<ll> sides;
    sides.push_back(left);
    sides.push_back(right);

    sort(sides.begin(), sides.end(), greater<ll>());
    ll L = zeros.size();
    ll sum = 0;
    ll ind = 0;
    if(K&1){
        K--;
        sum+=sides[0];
        ind=1;
    }

    ll i;
    for(i =0;i<L;i++){
        if(K<=2) break;
        sum += zeros[i];
        K-=2;
    }
    if(K>=2){
        ll temp=0;
        for(ll j=ind;j<2;j++){
            temp+=sides[j];
        }
        if(i<L){
            sum += max(temp, zeros[i]);
        }else{
            sum += temp;
        }
    }
    ll total=0;
    for(auto z:zeros) total+=z;
    // cout<<left<<":"<<right<<"\n";
    cout<<total+left+right-sum<<"\n";
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FIO
    ll T;
    cin >> T;
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