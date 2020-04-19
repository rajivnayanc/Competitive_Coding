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
int int_(char ch){
    return ch-'0';
}

char char_(int n){
    return n+'0';
}
int main(){
    FIO
    ll T;
    cin >> T;
    while (T--){
        string str1,str2;
        cin>>str1>>str2;
        ll L1 =str1.length(), L2=str2.length();
        string answer = "";
        if(L1>L2){
            answer += str1.substr(0,L1-L2);
            for(ll i = L1-L2,j=0;i<L1,j<L2;i++,j++){
                char ch = char_(int_(str1[i])^int_(str2[j]));
                answer+=ch;
            }
        }else{
            answer += str1.substr(0,L2-L1);
            for(ll i = L2-L1,j=0;i<L2,j<L1;i++,j++){
                char ch = char_(int_(str2[i])^int_(str1[j]));
                answer+=ch;
            }

        }
        cout<<answer<<"\n";
    }
    return 0;
}