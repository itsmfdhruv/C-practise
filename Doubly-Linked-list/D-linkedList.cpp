#include<iostream>

using namespace std;
//all time linked list code
class node{
    public :
    int data ;
    node* next ;
    node* prev ;

    node(int val){
        data = val ;
        next = NULL ;
        prev = NULL ;
    }
};

void insertAtHead(node* &head , int val){
    node* n = new node(val);
    n->next = head ;
    if(head != NULL){
    head->prev = n ;
    }
    head =n ;


}

void display(node* head){
    node* temp = head ;
    while(temp != NULL){
        cout << temp -> data << "-" ;
        temp = temp -> next ;
    }
    cout << "NULL" << endl ;
}

void insertAtTail(node* &head , int val){
    node* n = new node(val);

    if(head == NULL){
        insertAtHead(head , val);
        return ;
    }

    node* temp = head ;
    while(temp->next != NULL){
        temp = temp -> next ;
    }
    temp -> next = n;
    n->prev = temp ;
}

void deleteAtHead(node* &head){
    node* todelete = head ;
    head = head -> next ;
    head -> prev = NULL ;

    delete todelete ;
}

void deletion (node* &head, int pos){
    if(pos == 1){
        deleteAtHead(head) ;
        return ;
    }

    node* temp = head ;

    int count = 0 ;

    while(count != pos && temp != NULL){
        temp = temp -> next ;
        count ++ ;
    }

    temp -> prev = temp ->next ;
    if(temp -> next != NULL){
    temp -> next -> prev = temp -> prev ;
    }
    delete temp ;
}



int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head ,2 );
    insertAtTail(head , 3);
    insertAtTail(head, 4);
    display(head);
    insertAtHead(head , 0);
    
    display(head) ;
    
}
