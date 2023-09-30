#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class node{
    public:
        node* prev;
        int item;
        node *next;
};
class DCLL{
    public:
        node *start;
    public:
        DCLL();
        ~DCLL();
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
DCLL::DCLL(){
    start = NULL;
}
DCLL::~DCLL(){
    while(start)
        deleteFirstNode();
}
void DCLL::view(){
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
void DCLL:: viewRev(){
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
void DCLL::insertAtFirst(int data){
    node *n = new node;
    n->item = data;
    if(start == NULL){
        n->prev = n; 
        n->next = n;
    }else{
        n->next = start;
        n->prev = start->prev;
        start->prev->next = n;
        start->prev = n;
    }
        start = n;
}
void DCLL::insertAtLast(int data){
    node *n = new node;
    n->item = data;
    if(start == NULL){
        n->next = n;
        n->prev = n;
        start = n;
    }else{
        n->next = start;
        n->prev = start->prev;
        start->prev->next = n;
        start->prev = n;
    }
}
void DCLL::insertAfter(node *r,int data){
    node *n = new node;
    n->item = data;
    n->prev = r;
    n->next = r->next;
    r->next->prev = n;
    r->next = n;
}
node* DCLL :: searchNode(int data){
    node *t = start;
    do{
        if(t->item == data)
            return t;
        t = t->next;
    }while(t!=NULL);
    cout<<"Node Not Found\n";
    return NULL;
}
void DCLL::deleteLastNode(){
    node *lastNode = start->prev;
    if(start == NULL){
        cout<<"List is Empty\n";
    }
    else if(start->next == start){
        delete start;
        start = NULL;
    }
    else{
        start->prev = lastNode->prev;
        lastNode->prev->next = start;
        delete lastNode;
    }
}
void DCLL::deleteFirstNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else if(start->next == start){
        delete start;
        start = NULL;
    }
    else{
        node *firstNode = start;
        firstNode->next->prev = start->prev;
        start->prev->next = start->next;
        start = start->next;
        delete firstNode;
    }
}
int DCLL::deleteNode(node *r){ 
    //function to delete node and it also return deleted value
    node *t = start;
    if(start == NULL){
        cout<<"List is Empty\n";
        return -1;
    }
    else if(start == r){
        start->prev->next = start->next;
        start->next->prev = start->prev;
        start = r->next;
    }else{
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    int deletedValue = r->item;
    delete r;
    return deletedValue;
}
int main(){
    DCLL l;
    l.insertAtLast(10);
    l.deleteLastNode();
    l.view();
    return 0;
}


