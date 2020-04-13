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
    ll points[9][2]={{1,1},{2,4},{3,7},
                     {4,2},{5,5},{6,8},
                     {7,3},{8,6},{9,9}};
    cin >> T;
    ll sudoku[10][10];
    while (T--){
        for(ll i =1;i<=9;i++){
            for(ll j=1;j<=9;j++){
                char ch;
                cin>>ch;
                sudoku[i][j] = ch-'0';
            }
        }
        for(ll i=0;i<9;i++){
            ll x = points[i][0];
            ll y = points[i][1];
            sudoku[x][y]++;
            if(sudoku[x][y]==10)
                sudoku[x][y]=1;
        }
        for(ll i =1;i<=9;i++){
            for(ll j=1;j<=9;j++){
                cout<<sudoku[i][j];
            }
            cout<<endl;
        }

        
    }
    return 0;
}