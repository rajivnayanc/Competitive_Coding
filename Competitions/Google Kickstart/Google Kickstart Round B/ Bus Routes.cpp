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

ll solve(ll X[],ll N, ll D){
    vector<ll> temp1;
    temp1.push_back(-1);
    ll temp[N];
    for(ll i=0;i<N;i++){
        if(X[i]>(D/2)) temp1.push_back(i);
        temp[i]=(D/X[i]);
        temp[i]*=X[i];
    }
    if(temp1.size()==1){
        auto it = min_element(temp,temp+N);
        ll element = *it;
        ll position = it-temp;
        for(ll i =position+1;i<N;i++){

            ll K = ceil(((long double)(temp[i-1])/X[i]));
            temp[i] = K*X[i];
        }
        for(ll i =position-1;i>=0;i--){
            ll K = floor(((long double)(temp[i+1])/X[i]));
            temp[i] = K*X[i];
        }
    }else{
        ll prev,curr;
        for(ll it:temp1){
            if(it==-1){
                prev=it;
            }else{
                curr = it;
                for(ll i = curr-1;i>prev;i--){
                    ll K = floor(((long double)(temp[i+1])/X[i]));
                    temp[i] = K*X[i];
                }
                prev = it;
            }
        }
        for(ll i = curr+1;i<N;i++){
            ll K = ceil(((long double)(temp[i-1])/X[i]));
            temp[i] = K*X[i];
        }
    }
    for(int i =0;i<N;i++){
        cerr<<temp[i]<<" ";
    }
    cerr<<endl;
    return temp[0];    
}   
int main(){
    FIO
    ll T;
    cin >> T;
    for(int t =1;t<=T;t++){
        ll N,D;
        cin>>N>>D;
        ll X[N];
        inp(X,N)

        ll count = 0;
        count = solve(X,N,D);
        cout<<"Case #"<<t<<": "<<count<<"\n";
    }
    return 0;
}