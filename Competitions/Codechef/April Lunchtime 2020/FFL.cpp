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
    while (T--){
        ll N,S;
        cin>>N>>S;
        ll P[N],A[N];
        inp(P,N)
        inp(A,N)
        if(S>=100){
            cout<<"no\n";
            continue;
        }
        ll remaining = 100-S;
        ll min_defender = INT_MAX;
        ll min_forward = INT_MAX;
        fr(N){
            if(A[i]==0){
                min_defender = min(min_defender,P[i]);
            }
            if(A[i]==1){
                min_forward = min(min_forward,P[i]);
            }
        }

        ll total = min_defender+min_forward;
        if(total<=remaining){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
    return 0;
}