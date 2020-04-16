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
const ll MAX =1e6+5;
ll pos[MAX];

void swap(vector<ll> &arr, ll i, ll j){
    pos[arr[j]]=i;
    pos[arr[i]]=j;
    ll temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void solve(vector<ll> arr,ll K){
    ll N = arr.size()-1;
    for(ll i=1;i<=N;i++){
        pos[arr[i]]=i;
    }
    for(ll i=N;(i>0)&&(K>0);i--){
        ll wanted_pos = pos[i];
        if(wanted_pos!=i){
            K--;
            swap(arr,i,wanted_pos);
        }
    }
    for(ll i=N;i>0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}     
int main(){
    FIO
    ll N,K;
    cin>>N>>K;
    vector<ll> arr(N+1);
    for(ll i=N;i>=1;i--)
        cin>>arr[i];
    solve(arr,K);
    
    return 0;
}