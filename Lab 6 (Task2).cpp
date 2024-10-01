#include<iostream>
using namespace std;

struct node{
    int data;
    node*next;
};

void insertAtend(node** head, int newdata){
    node*newnode=new node();
    newnode->data=newdata;
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
        return;
    }
    node*last=*head;
    while(last->next != NULL){
        last=last->next;
    }
    last->next=newnode;
}

// void reverselist(node**head){
//     node*prev=NULL;
//     node*current=*head;
//     node*next=NULL;
//     while(current!=NULL){
//         next=current->next;
//         current->next=prev;
//         prev=current;
//         current=next;
//         *head=prev;
//     }
// }

void findmiddle(node*head){
    if(head==NULL){
        cout<<"The list is empty. "<<endl;
        return;
    }
    node*slow=head;
    node*fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"The middle element of the list is: "<<slow->data<<endl;
}

void printlist(node*node){
    cout<<"NULL"<<endl;
}
int main(){
    node*head=NULL;
    int n, value;
    cout<<"How many values do you want to insert in the list? "<<endl;
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<"Enter values "<<i+1<<": ";
        cin>>value;
        insertAtend(&head, value);
        
}

//out<<"The original list is: "<<endl;
printlist(head);

//reverselist(&head);

//cout<<"The reversed list is: "<<endl;
findmiddle(head);

//cout<<"After deleting the middle element: "<<endl;

node*temp=head;
int count=0;

while(temp!=NULL){
    count++;
    temp=temp->next;
}
printlist(head);
return 0;
}