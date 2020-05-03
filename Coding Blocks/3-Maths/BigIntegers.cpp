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

class BigInteger{
    public:
        string number;

        int number_compare(string a,string b);
        int number_compare_(string a,string b);

        string add(string a, string b);
        string add_(string a, string b);

        string subtract(string a, string b);
        string subtract_(string a, string b);

        string multiply(string a, string b);
        string multiply_(string a, string b);

        string divide(string a, int N);

        string factorial(int N);

    public:
        BigInteger(){
            number = "";
        }
        BigInteger(string a){
            number = a;
        }
        BigInteger operator+(BigInteger a);
        BigInteger operator+(int a);

        BigInteger operator-(BigInteger a);
        BigInteger operator-(int a);
        BigInteger operator*(BigInteger a);
        BigInteger operator*(int a);
        BigInteger operator/(BigInteger a);
        BigInteger operator/(int a);
        void operator=(string a);
        void operator=(BigInteger a);
        bool operator>(BigInteger a);
        bool operator<(BigInteger a);
        bool operator>=(BigInteger a);
        bool operator<=(BigInteger a);
        bool operator!=(BigInteger a);
        bool operator==(BigInteger a);
        friend ostream& operator<<(ostream & output, const BigInteger &a);
        friend istream& operator>>(istream &input, BigInteger &a);
};

string BigInteger::add(string a, string b){
    string ans = "";
    auto it1 = a.rbegin(),it2=b.rbegin();

    int curr = 0,remainder = 0;

    for(;it1!=a.rend()&&it2!=b.rend();it1++,it2++){
        curr = (*it1-'0')+(*it2-'0')+remainder;
        ans+=(char)((curr%10)+'0');
        remainder = curr/10;
    }
    for(;it1!=a.rend();it1++){
        int temp = (*it1-'0')+remainder;
        ans+=(char)(temp%10+'0');
        remainder = temp/10;
    }
    for(;it2!=b.rend();it2++){
        int temp = (*it2-'0')+remainder;
        ans+=(char)(temp%10+'0');
        remainder = temp/10;
    }
    if(remainder!=0){
        ans+=(remainder+'0');
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

string BigInteger::subtract(string A,string B){
    string ans = "";
    char sign = '+';
    string a,b;
    if(number_compare(A,B)>0){
        sign='+';
        a = A;
        b = B;
    }else if(number_compare(A,B)<0){
        sign='-';
        a = B;
        b = A;
    }else{
        return "0";
    }
    auto it1  = a.rbegin(),it2 = b.rbegin();
    int curr = 0, carry_over = 0;
    for(;(it1!=a.rend())&&(it2!=b.rend());it1++,it2++){
        int x = *it1-'0'-carry_over;
        int y = *it2-'0';
        if(x>=y){
            ans+=(x-y+'0');
            carry_over=0;
        }else{
            carry_over=1;
            x = 10+x;
            ans+=(x-y+'0');
        }
    }

    for(;it1!=a.rend();it1++){
        int x = *it1-'0'-carry_over;
        if(x<0){
            carry_over=1;
            x = 9;
        }else{
            carry_over=0;
        }
        ans+=(x+'0');
    }
    int L = ans.length();
    int k = L-1;
    while(ans[k]=='0'){
        k--;
    }
    ans.erase(k+1,L-k-1);
    if(sign=='-'){
        ans+=sign;
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

string BigInteger::multiply(string A, string B){
    string a,b;
    if(number_compare(A,B)>=0){
        a = A;
        b = B;
    }else{
        a = B;
        b = A;
    }
    string ans = "";
    int i = 0;

    for(auto it1 = b.rbegin();it1!=b.rend();it1++,i++){
        int y = (int)(*it1 - '0');
        int curr = 0, remainder = 0;
        int j = i;
        for(auto it = a.rbegin();it!=a.rend();it++){
            curr = (int)(*it -'0')*y+remainder;
            int L = ans.length();
            if(j==L){
                ans += (char)((curr%10)+'0');
                remainder = curr/10;
            }
            else{
                int temp = ans[j]+curr;
                temp = temp-'0';
                ans[j]=(char)(temp%10+'0');
                remainder = temp/10;
            }
            j++;
        }
        if(remainder!=0){
            ans+=(char)(remainder+'0');
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string BigInteger::divide(string number, int divisor){
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
       temp = temp * 10 + (number[++idx] - '0');

    while (number.size() > idx){
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
    if (ans.length() == 0)
        return "0";
    return ans;
}

int BigInteger::number_compare(string a,string b){
    if(a.length()>b.length())
        return 1;
    else if( a.length()<b.length())
        return -1;
    if(a.compare(b)==0)
        return 0;
    int L = a.length();
    bool flag = false;
    for(int i=0;i<L;i++){
        if((a[i]-'0')< (b[i]-'0')){
            flag = true;
            break;
        }else if((a[i]-'0')>(b[i]-'0')){
            flag = false;
            break;
        }
    }
    if(flag) return -1;
    else return 1;
}

int BigInteger::number_compare_(string a,string b){
    char sign1 = a[0], sign2 = b[0];
    if(sign1=='-') a.erase(a.begin());
    if(sign2=='-') b.erase(b.begin());

    int comp = number_compare(a,b);

    if(sign1!='-' && sign2=='-'){
        return 1;
    }else if(sign1=='-' && sign2!='-'){
        return -1;
    }else if(sign1=='-' && sign2=='-'){
        if(comp>0) return -1;
        if(comp<0) return 1;
        if(comp==0) return 0;
    }
    return comp;
}


string BigInteger::add_(string a, string b){
    char sign1 = a[0], sign2=b[0];
    string ans = "";
    if(sign1!='-'&&sign2=='-'){
        b.erase(b.begin());
        ans = subtract(a,b);
    }else if(sign1=='-'&&sign2!='-'){
        a.erase(a.begin());
        ans = subtract(b,a);
    }
    else if(sign1=='-'&&sign2=='-'){
        a.erase(a.begin());
        b.erase(b.begin());
        ans = add(b,a);
        ans.insert(0,"-");
    }else{
        ans  = add(a,b);
    }

    return ans;
}

string BigInteger::subtract_(string a, string b){
    char sign1 = a[0], sign2=b[0];
    string ans = "";
    if(sign1!='-'&&sign2=='-'){
        b.erase(b.begin());
        ans = add(a,b);
    }else if(sign1=='-'&&sign2!='-'){
        b.insert(0,"-");
        ans = add_(a,b);
    }
    else if(sign1=='-'&&sign2=='-'){
        b.erase(b.begin());
        ans = add_(b,a);
    }else{
        ans  = subtract(a,b);
    }
    return ans;
}

string BigInteger::multiply_(string a, string b){
    char sign1 = a[0], sign2 = b[0];
    string ans = "";
    if(sign1=='-'&&sign2=='-'){
        a.erase(a.begin());
        b.erase(b.begin());
        ans = multiply(a,b);
    }else if(sign1!='-'&&sign2=='-'){
        b.erase(b.begin());
        ans = multiply(a,b);
        ans.insert(0,"-");
    }else if(sign1=='-'&&sign2!='-'){
        a.erase(a.begin());
        ans = multiply(a,b);
        ans.insert(0,"-");
    }else if(sign1!='-'&&sign2!='-'){
        ans = multiply(a,b);
    }
    int L = ans.length();
    int sign = ans[0];
    int k=0,i;
    if(sign=='-'){
        k=1;
    }
    for(i = k;i<L;i++){
        if(ans[i]!='0') break;
    }
    if(i==L)
        return to_string(0);
    ans.erase(k,i-k);
    return ans;
}
string BigInteger::factorial(int N){
    if(N==0){
        return "1";
    }
    string ans = "1";
    for(int i= 1;i<=N;i++){
        string curr = to_string(i);
        ans = multiply(curr,ans);
    }
    return ans;
}

BigInteger BigInteger::operator+(BigInteger A){
    string b = A.number;
    string a = number;
    string answer = add_(a,b);
    BigInteger res = answer;
    return res;
}
BigInteger BigInteger::operator+(int A){
    string b = to_string(A);
    string a = number;
    string answer = add_(a,b);
    BigInteger res = answer;
    return res;
}
BigInteger BigInteger::operator-(BigInteger A){
    string b = A.number;
    string a = number;
    string answer = subtract_(a,b);
    BigInteger res = BigInteger(answer);
    return res;
}
BigInteger BigInteger::operator-(int A){
    string b = to_string(A);
    string a = number;
    string answer = subtract_(a,b);
    BigInteger res = BigInteger(answer);
    return res;
}

BigInteger BigInteger::operator*(BigInteger A){
    string b = A.number;
    string a = number;
    string answer = multiply_(a,b);
    BigInteger res = BigInteger(answer);
    return res;
}
BigInteger BigInteger::operator*(int A){
    string b = to_string(A);
    string a = number;
    string answer = multiply_(a,b);
    BigInteger res = BigInteger(answer);
    return res;
}

BigInteger BigInteger::operator/(int A){
    BigInteger ans;
    string temp = divide(number,A);
    ans.number = temp;
    return ans;
}
BigInteger BigInteger::operator/(BigInteger A){
    BigInteger ans;
    string temp = divide(number,stoi(A.number));
    ans.number = temp;
    return ans;
}
void BigInteger::operator=(string a){
    number = a;
}

void BigInteger::operator=(BigInteger a){
    number = a.number;
}

bool BigInteger::operator>(BigInteger a){
    if(number_compare_(number,a.number)>0){
        return true;
    }else return false;
}
bool BigInteger::operator<(BigInteger a){
    if(number_compare_(number,a.number)<0){
        return true;
    }else return false;
}
bool BigInteger::operator>=(BigInteger a){
    if(number_compare_(number,a.number)>=0){
        return true;
    }else return false;
}
bool BigInteger::operator<=(BigInteger a){
    if(number_compare_(number,a.number)<=0){
        return true;
    }else return false;
}
bool BigInteger::operator!=(BigInteger a){
    if(number_compare_(number,a.number)!=0){
        return true;
    }else return false;
}
bool BigInteger::operator==(BigInteger a){
    if(number_compare_(number,a.number)==0){
        return true;
    }else return false;
}

ostream& operator<<(ostream &output, const BigInteger &a){
    return output<<a.number;
}

istream& operator>>(istream &input, BigInteger &a){
    return input>>a.number;
}