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
        
int main(){
    FIO
    ll T;
    cin >> T;
    for(int t =1;t<=T;t++){
        ll N;
        cin>>N;
        ll arr[N];
        inp(arr,N)

        ll count = 0;
        for(ll i=1;i<(N-1);i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                count++;
            }
        }
        cout<<"Case #"<<t<<": "<<count<<"\n";
    }
    return 0;
}