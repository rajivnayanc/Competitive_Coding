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
pair<ll,ll> solve(string command){
    pair<ll,ll> answer;
    command = "1("+command+")";
    stack<ll> s;
    stack<pair<ll,ll>> s2;
    ll row=0,row_effective = 0;
    ll col=0,col_effective = 0;
    ll L = command.length();
    ll mod = 1e9;
    for(ll i =0;i<L;i++){
        if(command[i]>='0' && command[i]<='9'){
            s2.push(make_pair(row_effective,col_effective));
            s.push(command[i]-'0');
            row_effective=col_effective=0;
        }else if(command[i]=='(') continue;
        else{
            if(command[i]=='N'){
                row_effective--;
                row_effective%=mod;
                if(row_effective<0){
                    row_effective+=mod;
                    row_effective%=mod;
                }
            }else if(command[i]=='S'){
                row_effective++;
                row_effective%=mod;
                if(row_effective<0){
                    row_effective+=mod;
                    row_effective%=mod;
                }
            }else if(command[i]=='E'){
                col_effective++;
                col_effective%=mod;
                if(col_effective<0){
                    col_effective+=mod;
                    col_effective%=mod;
                }
            }else if(command[i]=='W'){
                col_effective--;
                col_effective%=mod;
                if(col_effective<0){
                    col_effective+=mod;
                    col_effective%=mod;
                }
            }else if(command[i]==')'){
                ll K = s.top();
                s.pop();
                row_effective*=K;
                col_effective*=K;
                pair<ll,ll> tt = s2.top();
                s2.pop();
                row_effective+=tt.first;
                col_effective+=tt.second;
                
                col_effective%=mod;
                if(col_effective<0){
                    col_effective+=mod;
                    col_effective%=mod;
                }

                row_effective%=mod;
                if(row_effective<0){
                    row_effective+=mod;
                    row_effective%=mod;
                }
            }
        }
    }
    row = (row+row_effective)%(mod);
    if(row<0){
        row+=mod;
        row %=mod;
    }
    col = (col+col_effective)%(mod);
    if(col<0){
        col+=mod;
        col %=mod;
    }
    answer.first = col+1;
    answer.second = row+1;
    return answer;
}       
int main(){
    FIO
    ll T;
    cin >> T;
    for(int t =1;t<=T;t++){
        string command;
        cin>>command;

        pair<ll,ll> answer;
        answer = solve(command);
        cout<<"Case #"<<t<<": "<<answer.first<<" "<<answer.second<<"\n";
    }
    return 0;
}