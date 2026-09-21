#include <bits/stdc++.h>

using namespace std;


struct Node{

    int data;
    Node* next;

    Node(int data){
        this->data=data;
    }
};

Node* rev(Node* head){


    if(!head->next) return head;

    Node* newH=rev(head->next);

    head->next->next=head;

    head->next=nullptr;

    return newH;
}




int main(){

    Node* head=new Node(0);
    Node* curr=head;
    for(int i=1;i<10;i++){
        curr->next=new Node(i);
        curr=curr->next;
    }

    Node* newH=rev(head);

    Node* temp=newH;

    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}