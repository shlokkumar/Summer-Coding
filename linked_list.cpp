#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};
node* A = NULL;

void insert_data_front(int x)
{
    node* temp = new node();
    if(A==NULL){
        temp->data = x;
        temp->next = NULL;
    }
    else{

        temp->data = x;
        temp->next = A;
    }
    A = temp;
}
void insert_data_back(int x)
{
    if(A==NULL){
        node* temp = new node();
        temp->data = x;
        temp->next = NULL;
        A = temp;
    }
    else{
        node * temp = A;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        node* temp2 = new node();
        temp2->data = x;
        temp2->next = NULL;
        temp->next = temp2;
    }
}

void traverse()
{
    node* temp = A;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

bool search_node(int x)
{
    node* temp = A;
    int f = 0, i=0;
    while(temp->next!=NULL){
            i++;
        if(temp->data==x){
            f=1;
            break;
        }
        temp = temp->next;
    }
    if(f==0){
        cout<<"\nNot found";
        return false;
    }
    else{
        cout<<"\nFound at "<<i<<" position";
        return true;
    }
}

void delete_node(int x)
{
    if(x!=0){
    node* temp = A;
    int i;
    for(i=0;i<x-2;i++){
        temp = temp->next;
    }
    node* temp2 = temp->next;
    temp->next = temp2->next;
    }
    else{
        A = A->next;
    }
    cout<<"\ndeleted\n";
}

void reverse_list(node* p)
{
    if(p->next==NULL){
        A = p;
        return;
    }
    reverse_list(p->next);
    node* q = p->next;
    q->next = p;
    p->next = NULL;
}
