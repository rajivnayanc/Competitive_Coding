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
class PrimePolynom{
public:
    int reveal(int A, int B, int C){
        int i =0;
        while(1){
            int temp = this->fn(A,B,C,i);
            if(!(this->if_prime(temp))){
                break;
            }
            i++;
        }
        return i;
    }
    int fn(int A, int B, int C, int M){
        int result = A*M*M + B*M+C;
        return result;
    }
    bool if_prime(int N){
        if((N<=0) || (N==1)) return false;
        for(int i=2;(i*i)<=N;i++){
            if((N%i)==0)
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    PrimePolynom obj = PrimePolynom();
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<obj.reveal(a,b,c)<<"\n";
    }
    return 0;
}



