// { Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void append(struct Node** headRef, int data)
{
	struct Node* new_node = new Node (data);
	struct Node *last = *headRef;
	
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

void printList(struct Node *tmp){
    while(tmp){
        cout<<tmp->data<<' ';
        tmp=tmp->next;
    }
    cout<<endl;
}

int countNodesinLoop(struct Node *head);

/* Drier program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, tmp;
        cin>>n;
        struct Node *head = NULL;
        struct Node* temp;
        struct Node *s;
        struct Node *t;
        cin>>tmp;
        append(&head, tmp);
        s=head;
        for(int i=1; i<n; i++){
            cin>>tmp;
            append(&head, tmp);
        }
        /* Create a loop for testing */
        // srand(time(NULL));
        int c;
        cin>>c;
        if(c>0){
            //c=c-1;
            temp=head;
            t = head;
            while(t->next)t=t->next;
            while(c--)temp=temp->next;
            t->next=temp;
            // s->next=temp;
        }
        //printList(head);
        cout<<countNodesinLoop(head)<<endl;
	}
    return 0;
}
// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Your task is to complete the function this function
// function should return the size of the loop
int countNodesinLoop(struct Node *head)
{
     if(head->next == NULL || head == NULL) return 0;
     
     unordered_map<Node*,int> m;
     int count = 0;
     Node* temp = NULL;
     
     for(Node* curr=head; curr!=NULL; curr = curr->next)
     {
         if(m.find(curr)!=m.end())
         {
             return count-m[curr]+1;
         }
         
         count++;
         m.insert({curr,count});
     }
     
     return 0;
}
