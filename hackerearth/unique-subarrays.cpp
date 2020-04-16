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
        
set<ll> s;
int main(){
    FIO
    ll T;
    cin >> T;
    while (T--){
        ll N;
        cin>>N;
        ll arr[N];
        inp(arr,N)
        ll answer = 0;
        ll j=0;
        for( ll i=0;i<N;i++){
            while(j<N && (s.find(arr[j])==s.end())){
                s.insert(arr[j]);
                j++;
            }
            answer += (j-i)*(j-i+1)/2;
            s.erase(arr[i]);
        }
        cout<<answer<<"\n";
        s.clear(); 
    }
    return 0;
}