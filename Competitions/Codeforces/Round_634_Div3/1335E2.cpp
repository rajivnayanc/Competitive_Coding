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
vector<ll> v;
vector<ll> occ[201];      
void largest_palindrome(ll &ans){
    ll x=0,y=0;
    ll l=0,r=v.size()-1;
    for(auto it:v)
        y+=it;
    ans = max(ans,y);
    bool br=false,bl=false;
    while(1){
        x++;
        br=false;
        bl=false;
        while(l<=r && !bl){
            if(v[l]){
                y--;
            }else{
                bl=true;
            }
            l++;
        }
        while(l<=r && !br){
            if(v[r]){
                y--;
            }else{
                br=true;
            }
            r--;
        }
        if(!br||!bl) break;

        ans = max(ans,2*x+y);
    }
}
int main(){
    FIO
    
    ll T;
    cin >> T;
    while (T--){
        ll N;cin>>N;
        ll arr[N];
        fr(N){
            cin>>arr[i];
            occ[arr[i]].push_back(i);
        }

        for(ll i=1;i<=200;i++)
            occ[i].push_back(N);
    
        ll ans = 0;
        for(ll i=1;i<=200;i++){
            if(occ[i].size()==1) continue;
            for(ll j=1;j<=200;j++){
                if(i==j){
                    ans = max((ll)(occ[i].size()-1),ans);
                    continue;
                }
                
                for(ll l=0,k=0;(l<(occ[i].size()-1))||(k<(occ[j].size()-1));){
                    if(occ[i][l]<occ[j][k]){
                        v.push_back(0);
                        l++;
                    }else{
                        v.push_back(1);
                        k++;
                    }
                }
                largest_palindrome(ans);
                v.clear();
            }
        }

        cout<<ans<<"\n";
        for(ll i=1;i<=200;i++){
            occ[i].clear();
        }


    }
    return 0;
}