#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class node{
    public:
        int item;
        node *next;
};
class CLL{
    private:
        node *start;
    public:
        CLL();
        ~CLL();
        void view();
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        node* searchNode(int);
        void deleteLastNode();
        void deleteFirstNode();
        int deleteNode(node*);
};
CLL::CLL(){
    start = NULL;
}
CLL::~CLL(){
    while(start)
        deleteFirstNode();
}
void CLL::view(){
    if(start==NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        do{
            cout<<t->item<<" ";
            t=t->next;
        }while(t!=start);
        cout<<endl;
    }
}
void CLL::insertAtLast(int data){
    node *n = new node;
    n->item = data;
    if(start == NULL){
        start = n;
        n->next = n;
    }else{
        n->next = start;
        node *t = start;
        while(t->next!=start)
            t=t->next;
        t->next = n;
    }
}
void CLL::insertAtFirst(int data){
    node *n = new node;
    n->item = data;
    if(start!=NULL){
        node *t = start;
        n->next = t;
        while(t->next!=start)
            t=t->next;
        t->next = n;
    }else
        n->next = n;
    start = n;
}
void CLL::insertAfter(node *r,int data){
    node *n = new node;
    n->item = data; 
    n->next = r->next;
    r->next = n;
}
node* CLL :: searchNode(int data){
    node *t = start;
    do{
        if(t->item == data)
            return t;
        t = t->next;
    }while(t!=start);
    cout<<"Node Not Found\n";
    return NULL;
}
void CLL :: deleteLastNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        node *t1 = NULL;
        while(t->next!=start){
            t1=t;
            t=t->next;
        }
        if(t1!=NULL)
            t1->next = start;
        else
            start = NULL;
        delete t;
    }
}
void CLL::deleteFirstNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        node *r = start;
        while(t->next!=start)
            t=t->next;
        t->next = start->next;
        start = start->next;
        delete r;
    }
}
int CLL::deleteNode(node *r){ 
    //function to delete node and it also return deleted value
    node *t = start;
    if(start == NULL){
        cout<<"List is Empty\n";
        return -1;
    }
    else if(start == r){
        start = r->next;
        while(t->next!=start)
            t=t->next;
        t->next = start;
    }
    else{
        while(r!=t->next)
            t=t->next;
        t->next = r->next;
    }
    int deletedValue = r->item;
    delete r;
    return deletedValue;
}
int main(){
    CLL l;
    l.insertAtLast(10);
    l.insertAtLast(20);
    l.insertAtLast(30);
    l.insertAtLast(40);
    l.insertAtLast(50);
    l.insertAtLast(60);
    l.insertAtFirst(999);
    l.insertAtFirst(8989);
    l.view();
    node *s = l.searchNode(60);
    cout<<s->next->item<<endl;
    l.view();
    return 0;
}
