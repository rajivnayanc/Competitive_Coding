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

void solve(ll t){
    ll N,K;cin>>N>>K;
    ll M[N];
    inp(M,N);
    ll max_diff = INT_MIN;
    ll ind = 0;
    for(ll i =1;i<N;i++){
        ll diff = M[i]-M[i-1];
        if(diff>=max_diff){
            max_diff = diff;
            ind = i;
        }
    }
    ll newS = (M[ind]+M[ind-1])/2;
    ll result = INT_MIN;
    max_diff = INT_MIN;
    for(ll i =1;i<N;i++){
        if(i!=ind){
            ll diff = M[i] - M[i - 1];
            if (diff >= max_diff){
                max_diff = diff;
                // ind = i;
            }
        }
    }
    result = max(max_diff,newS-M[ind-1]);
    result = max(result, -newS + M[ind]);

    cout << "Case #" << t << ": " << result << endl;
}

int main()
{
    FIO
        ll T;
    cin >> T;
    ll t = 0;
    while (T--){
        t++;
        solve(t);
    }
    return 0;
}