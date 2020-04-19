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
#define frk(i,n) for (ll i = 0; i < n; i++)
#define frs(a, b) for (ll i = a; i <= b, i++)
#define frn(a, b) for (ll i = a; i >= b, i--)
#define sumarray(arr, n, sum)  \
    for (ll i = 0; i < n; i++) \
        sum += arr[i];

int main()
{
    FIO
    ll T;
    cin >> T;
    while (T--){
       ll N,M;
       cin>>N>>M;
       ll F[N],P[N];
       inp(F,N)
       inp(P,N)
       ll result = INT_MAX;

       frk(i,M){
           ll cost_sum = 0;
           int flag = 0;

           frk(j,N){
               if(F[j]==(i+1)){
                   cost_sum+=P[j];
                   flag=1;
               }
           }
           if(flag){
               result = min(result,cost_sum);
           }
       }
       cout<<result<<endl;
    }
    return 0;
}