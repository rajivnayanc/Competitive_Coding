//For 50 Points //To-Do
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
#define frn(a, b) for (ll i = a; i >= b, i--)
#define sumarray(arr, n, sum)  \
    for (ll i = 0; i < n; i++) \
        sum += arr[i];

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}
struct node *search(struct node *root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}
int main()
{
    FIO
    ll T,S;
    cin>>T>>S;
    while(T--){
        ll N;
        cin>>N;
        ll A[N],B[N];

        inp(A,N)
        inp(B,N)

        sort(A,A+N);
        sort(B,B+N);
        struct node *root = NULL;
        ll count = 0;
        for(ll i =0;i<N;i++){
            if(i==0){
                if(A[i]>=B[i]){
                    cout<<"NO\n";
                    break;
                }
                else{
                    root = insert(root, A[i]);
                    insert(root, B[i]);
                    count+=2;
                    // print(temp);
                }
            }
            else{
                if(A[i]>=B[i]){
                    cout<<"NO\n";
                    break;
                }
                else{
                    if(search(root,A[i])){
                        insert(root, A[i]);
                        insert(root, B[i]);
                        count += 2;
                    }else{
                        cout<<"NO\n";
                        break;
                    }
                }
            }
        }
        
        if(count==2*N)
            cout<<"YES\n";
    }
    return 0;
}