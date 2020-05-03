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
void sort_(vector<ll> &v,ll K){
    ll N = v.size();
    for(ll i=0;i<N-K;i++){
        for(ll j = i+K;j<N;j+=K){
            if(v[i]>v[j]){
                swap(v[i],v[j]);
            }
        }
    }
}       
int main(){
    FIO
    ll T;
    cin >> T;
    while (T--){
        ll N,K;
        cin>>N>>K;
        vector<ll> v;
        ll t; 
        for(ll i =0;i<N;i++){
            cin>>t;
            v.push_back(t);
        }
        sort_(v,K);
        bool flag = is_sorted(v.begin(),v.end());
        if(!flag)
            cout<<"no\n";
        else
            cout<<"yes\n";
    }
    return 0;
}