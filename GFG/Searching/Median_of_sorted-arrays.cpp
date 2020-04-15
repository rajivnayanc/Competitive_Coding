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
#define all(a) a.begin(),a.end()
#define fr(n) for (ll i = 0; i < n; i++)
#define frk(i, n) for (ll i = 0; i < n; i++)
#define frs(a, b) for (ll i = a; i <= b; i++)
#define frn(a, b) for (ll i = a; i >= b; i--)
#define sumarray(arr, n, sum)  \
    for (ll i = 0; i < n; i++) \
        sum += arr[i];
double binarySHelper(vector<ll> v1,vector<ll>v2){
    ll n1 = v1.size();
    ll n2 = v2.size();
    ll l = 0,r=n1;
    while(l<=r){
        ll i = (r-l)/2+l;
        ll j = (n1+n2+1)/2-i;
        ll max1 = (i==0)?INT_MIN:v1[i-1];
        ll max2 = (j==0)?INT_MIN:v2[j-1];

        ll min1 = (i==n1)?INT_MAX:v1[i];
        ll min2 = (j==n2)?INT_MAX:v2[j];
        
        if(max1<=min2 && min1>=max2){
            if((n1+n2)%2==0){
                double ans = (max(max1,max2)+min(min1,min2))/2.0;
                // double ans = max(max1,max2);
                return ans;
            }else{
                double ans = max(max1,max2);
                return ans;
            }
        }else if(min1<max2) l = i+1;
        else r = i-1;
    }
}

double binaryS(vector<ll> v1,vector<ll>v2){
    int n1 = v1.size();
    int n2 = v2.size();
    double ans;
    if(n1>n2) ans = binarySHelper(v2,v1);
    else    ans = binarySHelper(v1,v2);

    return ans;
}
int main(){
    FIO
    ll T;
    cin>>T;
    while(T--){
        ll N,M;cin>>N>>M;
        vector<ll> v1(N),v2(M);
        inp(v1,N)
        inp(v2,M)
        cout<<floor(binaryS(v1,v2))<<"\n";
    }
    return 0;
}