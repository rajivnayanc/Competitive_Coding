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
    int t = 0;
    while (T--){
        t++;
        ll N,B;
        cin>>N>>B;
        ll A[N];
        inp(A,N)
        sort(A,A+N);
        ll count = 0 ;
        ll sum = 0;
        for(ll i =0;i<N;i++){
            if(sum+A[i]<=B){
                count++;
                sum+=A[i];
            }
        }
        cout<<"Case #"<<t<<": "<<count<<"\n";
    }
    return 0;
}