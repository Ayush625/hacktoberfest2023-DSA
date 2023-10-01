#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class node{
    public:
        node* prev;
        int item;
        node *next;
};
class DLL{
    private:
        node *start;
    public:
        DLL();
        ~DLL();
        void view();
        void viewRev();
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        node* searchNode(int);
        void deleteLastNode();
        void deleteFirstNode();
        int deleteNode(node*);
};
DLL::DLL(){
    start = NULL;
}
DLL::~DLL(){
    while(start)
        deleteFirstNode();
}
void DLL::view(){
    if(start==NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        while(t!=NULL){
            cout<<t->item<<" ";
            t=t->next;
        }
        cout<<endl;
    }
}
void DLL:: viewRev(){
    if(start==NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        while(t->next!=NULL)
            t=t->next;
            // int x =0;
        do{
            cout<<t->item<<" ";
            t=t->prev;
            // cout<<++x<<endl;
        }while(t!=NULL);
        cout<<endl;
    }
}
void DLL::insertAtLast(int data){
    node *n = new node;
    n->item = data;
    n->next = NULL;
    n->prev = NULL;
    if(start == NULL)
        start = n;
    else{
        node *t = start;
        while(t->next!=NULL)
            t=t->next;
        t->next = n;
        n->prev = t;
    }
}
void DLL::insertAtFirst(int data){
    node *n = new node;
    n->item = data;
    n->next = start;
    n->prev = NULL;
    start->prev = n;
    start = n;
}
void DLL::insertAfter(node *r,int data){
    node *n = new node;
    n->item = data;
    if(r->next==NULL){
        n->next = NULL;
    }
    else if(r->prev == NULL){
        n->next = r->next;
        r->next->prev = n;
    }
    else{
        n->next = r->next;
        r->next->prev = n;
    }
        n->prev = r;
        r->next = n;
}
node* DLL :: searchNode(int data){
    node *t = start;
    while(t!=NULL){
        if(t->item == data)
            return t;
        t = t->next;
    }
    cout<<"Node Not Found\n";
    return NULL;
}
void DLL::deleteLastNode(){
    if(start == NULL){
        // cout<<"::";
        cout<<"List is Empty\n";
    }
    else if(start->next == NULL){
        // cout<<":::";
        delete start;
        start = NULL;
    }
    else{
        node *t = start;
        while(t->next!=NULL)
            t = t->next;
            t->prev->next = NULL;
            delete t;
    }
}
void DLL::deleteFirstNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else if(start->next == NULL){
        delete start;
        start = NULL;
    }
    else{
        node *t = start;
        t->next->prev = NULL;
        start = t->next;
        delete t;
    }
}
int DLL::deleteNode(node *r){ 
    //function to delete node and it also return deleted value
    node *t = start;
    if(start == NULL){
        cout<<"List is Empty\n";
        return -1;
    }
    else if(start == r){
        r->next->prev = NULL;
        start = r->next;
    }else if(r->next == NULL){
        r->prev->next = NULL;
    }
    else{
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    int deletedValue = r->item;
    delete r;
    return deletedValue;
}
int main(){
    DLL l;
    l.insertAtLast(10);
    l.insertAtLast(20);
    l.insertAtLast(30);
    l.insertAtLast(40);
    l.insertAtLast(50);
    l.insertAtLast(60);
    l.insertAtLast(70);
    // l.deleteLastNode();
    l.insertAtFirst(999);
    l.insertAtFirst(998);
    // l.view();
    // node *t = l.searchNode(20);
    // l.insertAfter(t,6969);
    l.view();
    l.viewRev();
    // cout<<"::"<<l.start->next->item<<" ";
    // l.insertAtFirst(90);
    // l.insertAtLast(80);
    // l.view();
    // l.deleteFirstNode();
    // l.deleteFirstNode();
    // l.deleteLastNode();
    // l.view();
    // int data = l.deleteNode(t);
    // l.view();
    // cout<<data;
    return 0;
}

