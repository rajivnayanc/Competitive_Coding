// LRUCACHE.cpp


// Rajiv Nayan Choubey
// @rajivnayanc | @rajivnayanch
// May 19, 2021  18:23:41

#include <iostream>
#include <unordered_map>
using namespace std;

typedef int ll;

#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

typedef struct node{
    ll key;
    ll value;
    struct node * prev;
    struct node * next;
}Node;

class List{
private:
    Node * head;
    Node * tail;
    ll m_size;
public:
    List(){
        head = nullptr;
        tail = nullptr;
        m_size = 0;
    }
    ~List(){
        while(head){
            Node * temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        m_size = 0;
    }
 
    ll size(){return m_size;};
    Node * front(){return head;}
    Node * back(){return tail;}
 
    Node* newNode(ll key, ll val){
        Node * temp = new Node;
        temp->value = val;
        temp->key = key;
        temp->prev = nullptr;
        temp->next = nullptr;
        return temp;
    }
 
    void addFront(Node * node){
        if(head==nullptr){
            head = node;
            tail = node;
            m_size++;
            return;
        }
        head->prev = node;
        node->next = head;
        node->prev = nullptr;
        head = node;
        m_size++;
    }
    void addBack(Node * node){
        if(tail == nullptr){
            head = node;
            tail = node;
            m_size++;
            return;
        }
        node->prev = tail;
        tail->next = node;
        node->next = nullptr;
        tail = node;
        m_size++;
    }
 
    void deleteFront(){
        if(head!=nullptr){
            Node * temp = head;
            head = head->next;
            delete temp;
            if(head==nullptr) tail=nullptr;
            m_size--;
        }
    }
    void deleteBack(){
        if(tail!=nullptr){
            Node * temp = tail;
            tail = tail->prev;
            delete temp;
            if(tail==nullptr) head=nullptr;
            m_size--;
        }
    }
 
    void deleteNode(Node * node){
        if(node==tail){
            deleteBack();
        }else if(node==head){
            deleteFront();
        }else{
            Node * temp = node;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete temp;
            m_size--;
        }
    }
 
    void moveToBack(Node * node){
        if(node==tail){
            return;
        }else if(node==head){
            Node * temp = head;
            head = head->next;
            tail->next = temp;
            temp->prev = tail;
            temp->next = nullptr;
            tail = temp;
        }else{
            Node * temp = node;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            tail->next = temp;
            temp->prev = tail;
            temp->next = nullptr;
            tail = temp;
        }
    }
    void display(){
        Node * temp = head;
        while(temp){
            cout<<temp->value<<" ";
            temp = temp->next;
        }
    }
    
};

class LRUCache {
    List cache;
    unordered_map<int, Node*> mp;
    int K;
public:
    LRUCache(int capacity) {
        K = capacity;
        mp.clear();
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            int out = mp[key]->value;
            cache.moveToBack(mp[key]);
            return out;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]->value = value;
            cache.moveToBack(mp[key]);
            return;
        }else{
            if(cache.size()==K){
                auto front = cache.front();
                int keyT = front->key;
                mp.erase(keyT);
                cache.deleteFront();
            }
        }
        auto newN = cache.newNode(key,value);
        cache.addBack(newN);
        mp[key] = newN;
        
    }
};

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FIO
    ll K, N;
    cin>>K>>N;
    ll inp,val;char ch;
    LRUCache lru(K);
    for(ll i =0;i<N;i++){
        cin>>ch;
        if(ch=='p'){
            cin>>inp>>val;
            lru.put(inp,val);
            cout<<"NULL\n";
        }else{
            cin>>inp;
            cout<<lru.get(inp)<<"\n";
        }

    }
    return 0; 
}
