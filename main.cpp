#include <iostream>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* new_node(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* insert_data(int x, node* A)
{
    if(A==NULL){
        A = new_node(x);
    }
    else if(x <= A->data){
            A->left = insert_data(x, A->left);
    }
    else{
        A->right = insert_data(x, A->right);
    }
    return A;
}
void traverse_DLR(node* A)
{
    if(A==NULL){
        return;
    }
    else{
        cout<<A->data<<" ";
        traverse_DLR(A->left);
        traverse_DLR(A->right);
    }
}

void traverse_LDR(node* A)
{
    if(A==NULL){
        return;
    }
    else{
        traverse_LDR(A->left);
        cout<<A->data<<" ";
        traverse_LDR(A->right);
    }
}

void traverse_LRD(node* A)
{
    if(A==NULL){
        return;
    }
    else{
        traverse_LDR(A->left);
        traverse_LRD(A->right);
        cout<<A->data<<" ";
    }
}

int max_data(node* A)
{
    while(A->right!=NULL){
        A = A->right;
    }
    return A->data;
}

bool search_data(int x, node* A)
{
    if(A==NULL){
        return false;
    }
    if(x == A->data){
        return true;
    }
    else if(x <= A->data){
        search_data(x, A->left);
    }
    else{
        search_data(x, A->right);
    }
}

int main()
{
    cout << "Hello dsfT!" << endl;
    node* A = NULL;

    int n;
    A = insert_data(x, A); //'x' : value to enter, A = head node
    cout<<"traversing DLR : ";
    traverse_DLR(A);

    cout<<endl<<"traversing LDR : ";
    traverse_LDR(A);

    cout<<endl<<"traversing LRD : ";
    traverse_LRD(A);
    int x;
    cout<<"\nEnter number to search : ";
    cin>>x;
    bool s = search_data(x, A);
    if(s){
        cout<<"Found";
    }
    else{
        cout<<endl<<"Not found";
    }
    int c = max_data(A);
    cout<<endl<<"maximum element : "<<c;



    return 0;
}
