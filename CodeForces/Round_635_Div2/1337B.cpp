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
        ll x,n,m;
        cin>>x>>n>>m;
        ll dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=x;
        for(ll i=1;i<=n;i++){
            dp[i][0]=(ll)(dp[i-1][0]/2)+10;
        }
        for(ll i=1;i<=m;i++){
            dp[0][i] = dp[0][i-1]-10;
        }

        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                ll temp1 = ((ll)(dp[i-1][j])/2)+10;
                ll temp2 = (ll)dp[i][j-1]-10;
                dp[i][j] = min(temp1,temp2);
                dp[i][j] = min(dp[i][j],dp[i-1][j]);
                dp[i][j] = min(dp[i][j],dp[i][j-1]);
            }
        }

        if(dp[n][m]<=0){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}