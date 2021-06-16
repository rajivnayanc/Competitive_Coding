#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long int ll;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    FIO
    ll no_of_transactions, friends;
    cin>>friends>>no_of_transactions;

    string x,y; ll amount;

    map<string, ll> net;
    for(ll i=0;i<no_of_transactions;i++){
        cin>>x>>y>>amount;
        if(net.count(x)==0){
            net[x]=0;
        }
        if(net.count(y)==0){
            net[y]=0;
        }

        net[x] -= amount;
        net[y] += amount;
    }
    ll count =0;
    
    priority_queue<pair<ll, string>> debit_queue, credit_queue;
    for(auto p:net){
        string person = p.first;
        ll amount = p.second;
        if(amount> 0){
            credit_queue.push(make_pair(amount, person));
        }
        if(amount< 0){
            debit_queue.push(make_pair(amount, person));
        }
    }
    vector<pair<pair<string, string>,ll>> out;
    while(!credit_queue.empty() && !debit_queue.empty()){
        auto from = debit_queue.top();debit_queue.pop();
        auto to = credit_queue.top();credit_queue.pop();

        ll settled_amount = min(-from.first, to.first);
        from.first += settled_amount;
        to.first -= settled_amount;

        // cout<<count+1<<": "<<from.second<<" will pay "<<settled_amount<<" to "<<to.second<<"\n";
        out.push_back(make_pair(make_pair(from.second, to.second),settled_amount));
        if(from.first!=0){
            debit_queue.push(from);
        }
        if(to.first!=0){
            credit_queue.push(to);
        }
        count+=1;
    }

    cout<<count<<endl;
    for( auto o:out){
        cout<<o.first.first<<" "<<o.first.second<<" "<<o.second<<"\n";
    }

    return 0;
}
