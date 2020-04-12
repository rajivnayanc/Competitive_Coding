#include <bits/stdc++.h>
using namespace std;

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
       
ll countSetBits(ll n){
    ll ans = 0;
    while(n){
        n = n&(n-1);
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
vector<ll> SumSubsets(vector<ll> v){
    ll L = v.size();
    ll END = power(2,L);
    vector<ll> result;
    for(ll i =0;i<END;i++){
        ll safe = i;
        ll sum = 0;
        while(safe){
            ll p = safe&(-safe);
            ll pos = log2(p);
            sum+=v[pos];
            safe-=p;
        }
        result.push_back(sum);
    }
    return result;
}
int main(){
	FIO
	ll N,A,B;
    cin>>N>>A>>B;
    ll S[N];
    inp(S,N)
    ll n1=N/2;
    ll n2 = N-n1;
    vector<ll>v1,v2;
    for(ll i=0;i<N;i++){
        if(i<n1){
            v1.push_back(S[i]);
        }else{
            v2.push_back(S[i]);
        }
    }
    vector<ll> sum1,sum2;
    sum1 = SumSubsets(v1);
    sum2 = SumSubsets(v2);
    sort(sum2.begin(),sum2.end());
    
    ll L = sum1.size();
    ll result = 0;
    for(ll i =0;i<L;i++){
        auto it1 = lower_bound(sum2.begin(),sum2.end(),A-sum1[i]);
        auto it2 = upper_bound(sum2.begin(),sum2.end(),B-sum1[i]);
        ll l = it1-sum2.begin();
        ll k = it2-sum2.begin();
        result+=(k-l);
    }
    cout<<result;
	return 0;
}