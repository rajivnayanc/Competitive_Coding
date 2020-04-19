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
void print(ll a, ll b){
    cout<<a<<" "<<b<<"\n";
}
int main()
{
    FIO
    ll T;
    cin >> T;
    while (T--){
        ll r0,c0;
        cin>>r0>>c0;
        ll i=0,j=0;
        ll count = 26;
        if(r0!=1 || c0!=1){

            if(r0>c0){
                count += 2;
                ll t = (r0-c0)/2;
                cout << count << "\n";
                print(r0,c0);
                print(r0-t,c0+t);
            }
            else if(r0<c0){
                count += 2;
                cout << count << "\n";
                ll t = (c0 - r0) / 2;
                print(r0, c0);
                print(r0+t, c0-t);
            }else if(r0==c0){
                count += 1;
                cout << count << "\n";
                print(r0, c0);
            }

        }else{
            cout << count << "\n";
        }
        
        while(i<8 || j<8){
            
            ll left_offset;
            ll right_offset;
            left_offset = min(i, 8-j-1);
            right_offset = min(8-i-1,j);
            // print(left_offset,right_offset);cout<<"|";
            print(i + 1, j + 1);
            if(left_offset!=0){
                print(i - left_offset + 1, j + left_offset + 1);
                print(i + right_offset + 1, j - right_offset + 1);
                print(i + 1, j + 1);
            }
            
            i++;j++;
        }
    }
    return 0;
}