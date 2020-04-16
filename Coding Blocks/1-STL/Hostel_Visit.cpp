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
        
ll dist(ll x, ll y){
    return x*x+y*y;
}
int main(){
    FIO
    ll Q,K;
    cin >> Q>>K;
    priority_queue<ll> pq;
    while (Q--){
        ll q,x,y;
        cin>>q;
        if(q==1){
            cin>>x>>y;
            ll dist_ = dist(x,y);
            pq.push(dist_);
            if(pq.size()>K)
                pq.pop();
        }else if(q==2){
            cout<<pq.top()<<"\n";
        }
    }
    return 0;
}