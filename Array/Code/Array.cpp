#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Array{
private:
    int capacity;
    int lastIndex;
    int *ptr;
public:
    Array(){}
    Array(int size){
        this->capacity = size;
        this->lastIndex = -1;
        this->ptr = new int[size];
    }
    ~Array(){
        delete this->ptr;
        delete this;
    }
    Array* CreateArray(int size){
        this->capacity = size;
        this->lastIndex = -1;
        this->ptr = new int[size];
    }
    void view(){
        cout<<"LastIndex: "<<lastIndex<<"\n";
        for(int i=0;i<=this->lastIndex;i++){
            cout<<this->ptr[i]<<" ";
        }
        cout<<endl;
    }
    void insert(int index,int data){
        if(index<0 || index>lastIndex+1)
            cout<<"Invalid Index\n";
        else if(lastIndex == capacity-1)
            cout<<"Array is Full\n";
        else{
            for(int i=lastIndex; i>=index; i--)
                this->ptr[i+1] = ptr[i];
            this->ptr[index] = data;
            lastIndex++;
        }
    }
    void remove(int index){
        if(this->lastIndex == -1)
            cout<<"Array is Empty\n";
        else if(index<0 || index>lastIndex+1)
            cout<<"Invalid Index\n";
        else{
            for(int i=index+1;i<=lastIndex;i++)
                ptr[i-1] = ptr[i];
            lastIndex--;
        }
    }
    int getElement(int index){
        if(this->lastIndex == -1)
            cout<<"Array is Empty\n";
        else if(index<0 || index>lastIndex+1)
            cout<<"Invalid Index\n";
        else
            return ptr[index];
    }
    int count(){
        return this->lastIndex+1;
    }
    int search(int item){
        for(int i=0;i<=this->lastIndex;i++)
            if(this->ptr[i]==item)
                return i;
            return -1;
    }

};
int main(){
    Array arr(5);
    arr.CreateArray(5);
    arr.insert(0,10);
    arr.insert(1,20);
    arr.insert(2,30);
    arr.insert(3,40);
    arr.insert(4,50);
    arr.insert(5,60);
    arr.view();
    // arr.remove(3); 
    // arr.view();
    return 0;
}
