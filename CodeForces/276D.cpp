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

ll power(ll x,ll y){
    ll res = 1;
    while(y){
        if(y&1) res = res*x;
        x*=x;
        y>>=1;
    }
    return res;
}

ll solve(ll l,ll r){
    if(l==r){
        return 0;
    }
    ll temp = l^r;
    ll pos = 0;
    while(temp){
        pos++;
        temp>>=1;
    }
    return power(2,pos)-1;
}		
ll solve2(ll l,ll r){
    ll L=l,R=r;
    if(l==r) return 0;
    ll temp = log2(r);
    int k=0;
    while(temp>=0){
        ll pp = power(2,temp);
        ll i = (l/pp)&1;
        ll j = (r/pp)&1;
        if(k==0){ 
            temp--;
            k++;
            continue;
        }
        if((i^j)==0){
            if(i==0){
               ll temp = (pp)|l;
               if(temp<R)
                l=temp;
            }
            if(i==1){
                ll temp = (~((pp))&r);
                if(temp>L)
                    r=temp;
            }
        }
        temp--;
    }
    return (l^r);
}
int main()
{
	FIO
	ll l,r;
    cin>>l>>r;
    cout<<solve2(l,r);
	return 0;
}