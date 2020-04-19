#include <bits/stdc++.h>
using namespace std;

class Qry{
    public:
        int l;
        int r; 
        int x; 
        int id;
};

class AE{
    public:
        int v, id;
};

int f1(Qry q1, Qry q2){
    return (q1.x < q2.x)?1:0;
}

int f2(AE x, AE y){
    return (x.v < y.v)?1:0;
}

void update_bit(int bit[], int id, int v, int N){
    for (; id <= N; id += id & -id)
        bit[id] += v;
}

int q(int bit[], int id, int N){
    int output = 0;
    for (; id > 0; id -= id & -id)
        output += bit[id];
    return output;
}

void solve(Qry queries[], AE arr[], int ans[], int N, int Q){
    int bit[N + 1];
    for(int i =0;i<N+1;i++)
        bit[i]=0;

    sort(arr, arr + N, f2);

    sort(queries, queries + Q, f1);

    int now = 0;

    for (int i = 0; i < Q; i++){

        while (arr[now].v < queries[i].x && now < N)
        {

            update_bit(bit, arr[now].id + 1, 1, N);
            now++;
        }

        ans[queries[i].id] = q(bit, queries[i].r + 1, N) - q(bit, queries[i].l, N);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int N, Q;
        cin >> N >> Q;

        int A[N];
        for(int i =0;i<N;i++)
            cin>>A[i];

        AE arr1[N],arr2[N]; //arr_start, arr_end

        for (int i = 0; i < N - 1; i++){
            arr1[i].v = -min(A[i], A[i + 1]);
            arr2[i].v = max(A[i], A[i + 1]);
            arr1[i].id = i;
            arr2[i].id = i;
        }

        Qry query1[Q], query2[Q]; //query_start,query_end
        int actual[Q];
        for (int i = 0; i < Q; i++){
            int x1, x2, y;
            cin >> x1 >> x2 >> y;
            query1[i].l = x1 - 1;
            query1[i].r = x2 - 2;
            query1[i].x = -y;
            query1[i].id = i;

            query2[i].l = x1 - 1;
            query2[i].r = x2 - 2;
            query2[i].x = y;
            query2[i].id = i;
            actual[i] = x2 - x1;
        }
        int ans1[Q],ans2[Q];

        solve(query1, arr1, ans1,N-1,Q);
        solve(query2, arr2, ans2,N-1,Q);

        for (int i = 0; i < Q; i++)
            cout << actual[i] - ans1[i] - ans2[i] << endl;
    }
    return 0;
}