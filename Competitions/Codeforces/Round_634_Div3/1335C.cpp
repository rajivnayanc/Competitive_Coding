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
    // FIO
    ll T;
    cin >> T;
    while (T--){
        ll N;
        cin>>N;
        ll arr[N];
        inp(arr,N)
        ll freq[N+1];
        if(N==1){
            cout<<"0\n";
            continue;
        }
        if(N==2){
            cout<<"1\n";
            continue;
        }
        memset(freq,0,sizeof(freq));
        for(ll i=0;i<N;i++){
            freq[arr[i]]++;
        }
        ll unique = 0;
        vector<ll> v;
        for(ll i =0;i<=N;i++){
            if(freq[i]>0){
                unique++;
                v.push_back(freq[i]);
            }
        }
        ll ans = 0;
        if(unique==1){
            cout<<"1\n";
            continue;
        }
        auto max_freq = max_element(v.begin(),v.end());
        ll maxi = *max_freq;
        if(maxi>unique)
            ans=unique;
        else if(maxi==unique){
            ans = unique-1;
        }
        else if(maxi<unique){
            ans = maxi;
        }
        cout<<ans<<"\n";
        
    }
    return 0;
}