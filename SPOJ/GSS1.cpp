// GSS1.cpp


// Rajiv Nayan Choubey
// @rajivnayanc | @rajivnayanch
// August 23, 2020  22:34:43

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef int ll;
const ll MAX = 5e4+5000;
const ll INT_MIN_ = -1e6;
const ll MOD = 1e9+7;

#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define inp(arr, n) for (ll i = 0; i < n; i++) cin >> arr[i];
#define fr(n) for (ll i = 0; i < n; i++)
#define frk(i, n) for (ll i = 0; i < n; i++)
#define frs(a, b) for (ll i = a; i <= b; i++)
#define frn(a, b) for (ll i = a; i >= b; i--)
#define sumarray(arr, n, sum) for (ll i = 0; i < n; i++) sum += arr[i];
#define all(v) v.begin(), v.end()
#define pp(a) pair<a, a>
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
            pbds_set;

typedef struct node{
    ll prefixSum;
    ll suffixSum;
    ll sum;
    ll maxSum;
} Node;

ll arr[MAX+1];
Node segmentTree[4*MAX+5];

void makeSegmentTree(ll idx, ll ss, ll se){
    if(ss==se){
        segmentTree[idx] = ((Node){arr[ss],arr[ss],arr[ss],arr[ss]});
    }else{
        ll mid = (ss+se)/2;
        makeSegmentTree(2*idx+1,ss,mid);
        makeSegmentTree(2*idx+2,mid+1,se);

        Node left = segmentTree[2*idx+1];
        Node right = segmentTree[2*idx+2];

        segmentTree[idx].prefixSum = max(left.prefixSum,left.sum+right.prefixSum);
        segmentTree[idx].suffixSum = max(right.suffixSum,right.sum+left.suffixSum);
        segmentTree[idx].sum = left.sum+right.sum;
        segmentTree[idx].maxSum = max(left.suffixSum+right.prefixSum,max(left.maxSum,right.maxSum));
    }
}

Node queryMaxSum(ll idx, ll ss, ll se, ll qs, ll qe){
    if(qs<=ss && se<=qe) return segmentTree[idx];

    if(qs>se || qe<ss) return ((Node){INT_MIN_,INT_MIN_,INT_MIN_,INT_MIN_});

    ll mid = (ss+se)/2;

    Node left = queryMaxSum(2*idx+1,ss,mid,qs,qe);
    Node right = queryMaxSum(2*idx+2,mid+1,se,qs,qe);
    Node answer;
    answer.prefixSum = max(left.prefixSum,left.sum+right.prefixSum);
    answer.suffixSum = max(right.suffixSum,right.sum+left.suffixSum);
    answer.sum = left.sum+right.sum;
    answer.maxSum = max(left.suffixSum+right.prefixSum,max(left.maxSum,right.maxSum));
    
    return answer;
}

void solve(){
    ll N;cin>>N;
    inp(arr,N)
    makeSegmentTree(0,0,N-1);
    ll M;cin>>M;
    ll l,r;
    for(ll i=0;i<M;i++){
        cin>>l>>r;

        Node answer = queryMaxSum(0,0,N-1,l-1,r-1);
        cout<<answer.maxSum<<"\n";
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FIO
    ll T;
    // cin >> T;
    T=1;
    while (T--){
        solve();
    }
    return 0;
}