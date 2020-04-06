#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MAX = 2e6+5;
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

class Refactoring{
public:
    int refactor(int N,int start=2){
        int result=0;
        for(int i=start;(i*i)<=N;i++){
            if((N%i)==0){
                result++;
                result+=refactor(N/i,i);
            }
        }
        return result;
    }
 
};

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    Refactoring obj = Refactoring();
    while(t--){
        int N;
        cin>>N;
        cout<<obj.refactor(N)<<endl;
    }
    return 0;
}