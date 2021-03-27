// MoonsAndUmbrellas.cpp


// Rajiv Nayan Choubey
// @rajivnayanc | @rajivnayanch
// March 27, 2021  20:10:28


// Passing Test Set 1 and 2, Failing Test Set 3 (-ve cost)
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

ll countCJ_JC(string str, ll X, ll Y){
    ll CJ_c = 0;
    ll JC_c = 0;
    for(ll i = 0; i<(str.length()-1);i++){
        string temp = str.substr(i,2);
        if(temp.compare("CJ")==0) CJ_c++;
        if(temp.compare("JC")==0) JC_c++;
    }
    return CJ_c*X + JC_c*Y;
}

void minCost(string str, string curr, ll &cost, ll i, ll L , ll X, ll Y){
    if(i==L){
        cost = min(cost,countCJ_JC(curr, X, Y));
        return;
    }
    char curr_ch = str[i];
    if(curr_ch=='?'){
        minCost(str, curr+'C',cost,i+1,L,X,Y);
        minCost(str, curr+'J',cost,i+1,L,X,Y);
    }else{
        minCost(str, curr+curr_ch,cost,i+1,L,X,Y);
    }

}
void solve(ll t){
    ll x, y; string str;
    cin>>x>>y>>str;
    ll L = str.length();
    ll cost = 0;
    bool flag = false;
    for(ll i =0;i<L;){
        if(!flag){
            if(str[i]!='?'){
                flag=true;
                continue;
            }
            i++;
        }else{
            ll j = i;
            while(j<L){
                j++;
                if(str[j]!='?'){
                    break;
                }
            }
            if(j<L){
                if(str[i]!=str[j]){
                    if(str[i]=='C') cost+=x;
                    if(str[i]=='J') cost+=y;
                }
            }
            i = j;
        }
    }
    
    cout<<"Case #"<<t<<": "<<cost<<"\n";
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FIO
    ll T;
    cin >> T;
   for(ll t=1;t<=T;t++){
        solve(t);
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