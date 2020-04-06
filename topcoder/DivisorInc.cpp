#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MAX = 1e5+5;
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
int dp[MAX+1];		
class DivisorInc{
public:
    int countOperations(int N,int M){
        if(N>M){
            return -1;
        }
        if(N==M){
            return 0;
        }
        for(int i=0;i<=MAX;i++)
            dp[i]=INT_MAX;
        dp[N] = 0;
        for(int i =N;i<=M;i++){
            if(dp[i]==INT_MAX) continue;
            for(int j=2;(j*j)<=i;j++){
                if((i%j)!=0) continue;
                if((i+j)>M)continue;
                dp[i+j] = min(dp[i+j],dp[i]+1);
                if((i+(i/j))>M) continue;
                dp[i+(i/j)] = min(dp[i+(i/j)],dp[i]+1);
            }
        }
        return (dp[M]==INT_MAX)?-1:dp[M];
    }
    
};

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    DivisorInc obj = DivisorInc();
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<obj.countOperations(n,m)<<"\n";
    }
    return 0;
}



