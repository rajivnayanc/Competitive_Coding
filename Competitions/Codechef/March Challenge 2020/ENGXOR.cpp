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
#define frs(a, b) for (ll i = a; i <= b, i++)
#define frn(a, b) for (ll i = a; i >= b, i--)
#define sumarray(arr, n, sum)  \
    for (ll i = 0; i < n; i++) \
        sum += arr[i];

ll countOnes(ll n)
{
    ll count = 0;
    while (n){
        n &= (n - 1);
        count++;
    }
    return count;
}

int main()
{
    FIO
    ll T;
    cin >> T;
    while (T--){
        ll N, Q;
        cin >> N >> Q;
        ll A[N];
        inp(A, N)
        ll even = 0,odd=0;
        frk(i,N){
            ll temp = countOnes(A[i]);
            if(temp%2) odd++;
            else even++;
        }
        frk(i,Q){
            ll P; cin>>P;
            ll temp = countOnes(P);
            if(temp%2)
                cout<<odd<<" "<<even<<"\n";
            else
                cout << even << " " << odd << "\n";
        }
        
    }
    return 0;
}