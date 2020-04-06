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
class PrimeAnagrams{
public:
    vector<bool> is_prime;
    vector<int> all_primes;

    vector<int> primes(string str){
        vector<int> res;
        this->sieve(MAX);
        res.clear();
        int prod = 0;

        sort(str.begin(),str.end());
        int a,b,c,L;
        L = str.size();
        do{
            if(str[0]=='0')
                continue;
            a = 0;
            for(int i =0;i<L-2;i++){
                a = 10*a + (str[i]-'0');
                if(str[i+1]=='0' ||!(this->is_prime[a])) continue;
                b = 0;
                for(int j=i+1;j<L-1;j++){
                    b = 10*b + (str[j]-'0');
                    if(str[j+1]=='0' ||!(this->is_prime[b])) continue;
                    c = 0;
                    for(int k =j+1;k<L;k++)
                        c = 10*c + (str[k]-'0');
                    if(this->is_prime[c]){
                        long long int temp = a*b*c;
                        if(res.empty()||(temp<prod)){
                            res.clear();
                            res.push_back(a);
                            res.push_back(b);
                            res.push_back(c);
                            prod=temp;
                        }
                    }
                    
                }
            }
            
        }while(next_permutation(str.begin(),str.end()));
        sort(res.begin(),res.end());
        return res;
    }
    
    

    void sieve(int N){
        this->is_prime.resize(N+1);
        fill(this->is_prime.begin(),this->is_prime.end(),true);
        this->is_prime[0]=this->is_prime[1]=false;
        for(int i=2;(i*i)<=N;i++){
            if(this->is_prime[i]){
                for(int j=i*i;j<=N;j+=i){
                    this->is_prime[j]=false;
                }
            }
        }
        for(int i=0;i<=N;i++){
            if(this->is_prime[i]) this->all_primes.push_back(i);
        }
    }
};

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    PrimeAnagrams obj = PrimeAnagrams();
    while(t--){
        string str;
        cin>>str;
        vector<int> res = obj.primes(str);
        int L = res.size();
        for(auto it:res)
            cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}