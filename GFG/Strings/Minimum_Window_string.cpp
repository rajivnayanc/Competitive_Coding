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

string solve(string str1,string str2){
    ll L1 = str1.length();
    ll L2 = str2.length();
    if(L1<L2){
        return "-1";
    }
    ll max_size = 256;
    ll hash1[max_size];
    ll hash2[max_size];
    memset(hash1,0,sizeof(hash1));
    memset(hash2,0,sizeof(hash2));
    for(char ch:str2){
        hash2[ch]++;
    }
    ll min_len = INT_MAX, min_start_ind=-1,count=0,start=0;
    for(ll i = 0;i<L1;i++){
        hash1[str1[i]]++;
        if((hash2[str1[i]]!=0) && (hash1[str1[i]]<=hash2[str1[i]]))
            count++;

        if(count==L2){
            while( (hash2[str1[start]]==0) || (hash1[str1[start]]>hash2[str1[start]])){
                if((hash1[str1[start]]>hash2[str1[start]]))
                    hash1[str1[start]]--;
                start++;
            }
            ll new_length = i-start+1;
            if(min_len>new_length){
                min_len=new_length;
                min_start_ind=start;
            }
        }
    }
    if(min_start_ind==-1)
        return "-1";
    else
        return str1.substr(min_start_ind,min_len);
    

}
int main(){
    FIO
    ll T;
    cin>>T;
    cin.ignore();
    while(T--){
        string str1,str2;
        getline(cin,str1);
        getline(cin,str2);
        cout<<solve(str1,str2)<<"\n";
    }
    return 0;
}