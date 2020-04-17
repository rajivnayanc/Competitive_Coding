#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll MOD = 1000000007;
const ll MAX = 2e5+7;


ll inverse2(ll m1, ll p1){
	ll i = 1;
	while(1){
	if((m1*i) % p1 == 1)
		return i;
	i++;
 	}
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
  
long long int powll(ll x, ll y, ll mod){
    
    ll result = 1;
    while(y>0){
        if(y&1) result = (result*x)%mod;
        x = (x*x)%mod;
        y/=2;
    }
    return result;
}
ll mul(ll a, ll b, ll mod){
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

ll add(ll a, ll b,ll mod){
    ll temp = (a%mod + b%mod)%mod;
    if(temp<0) 
        temp = (temp+mod)%mod;
    return temp;
}

ll fact[MAX+1];
ll fact_41[MAX+1];
ll fact_41_p[MAX+1];
ll fact_2[MAX+1];
void factorials(){
	fact[0] = 1;
	fact_2[0]=1;

	fact_41[0] = 1;
	fact_41_p[0] = 0;

	ll tmd = 148721;
	ll tmd2 = 1681;
	for(int i = 1; i <=MAX; ++i){
		fact[i] = mul(fact[i - 1], i,tmd);
		fact_2[i] = mul(i,fact_2[i - 1],2);
		ll y = i;
		fact_41_p[i] = fact_41_p[i - 1];
		while(y % 41 == 0){
 			y = y / 41;
 			fact_41_p[i]++;
		}
 		fact_41[i] = mul(y,fact_41[i - 1],tmd2);
	}
}

ll CRT(ll num[], ll rem[], ll k) { 
    ll prod = 1; 
    for (ll i = 0; i < k; i++) 
        prod *= num[i]; 
  
    ll result = 0;

    for (ll i = 0; i < k; i++) { 
        ll pp = prod / num[i];
		ll temp = mul(rem[i],modInverse(pp, num[i]),prod); 
		temp = mul(temp,pp,prod); 
        result = add(result,temp,prod); 
    } 
    return result % prod; 
}

int main(){
	FIO
	factorials();
	
	ll t;
	cin >> t;
	while (t--){
		ll a, b, n;
		cin >> a >> b >> n;
		if(a == 0 && b == 0){
			cout <<"1\n";
			continue;
		}
		if(b == 0){
			cout << "1\n";
			continue;
 		}
		if(b==1){
			cout<<a<<"\n";
			continue;
		}
		ll mod1 = 2;
		ll mod2 = 41*41;
		ll mod3 = 148721;

		ll r1 = (n == 0) ? 1 : 0;

		ll r2 = mul(fact_41[2 * n],inverse2(fact_41[n],mod2),mod2);
		r2 = mul(r2,inverse2(fact_41[n], mod2),mod2);
		r2 = mul(r2 , powll(41, fact_41_p[2 * n] - 2 * fact_41_p[n], 1681),mod2);

		ll r3 = mul(fact[2 * n],modInverse(fact[n],mod3),mod3);
		r3 = mul(r3,modInverse(fact[n], mod3),mod3);

		ll num[]={mod1,mod2,mod3};
		ll rem[]={r1,r2,r3};
		ll ans = CRT(num,rem,3);
		
		ll y;
		ll temp = powll(b,ans,(mod1*mod2*mod3+1));
		ll num2[] = {2,(mod1*mod2*mod3+1)};
		ll rem2[] = {b%2,temp};
		y = CRT(num2,rem2,2);
		ll result = powll(a, y, MOD);
		cout << result << "\n";
	}
	return 0;
}