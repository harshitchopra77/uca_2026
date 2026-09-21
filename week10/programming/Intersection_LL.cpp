#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data=data;
    }
};

Node* intersection(Node* head1,Node* head2){
    Node* curr1=head1;
    Node* curr2=head2;

    Node* result=nullptr;
    Node* tail=NULL;

    while(curr1 && curr2){


        if(curr1->data == curr2->data){

            if(result==nullptr){
                result=new Node(curr2->data);
                tail=result;

            }   
            else {
                tail->next=new Node(curr2->data);
                tail=tail->next;
            }
            curr1=curr1->next;
            curr2=curr2->next; 
        }
        else if(curr1->data < curr2->data){
            curr1=curr1->next;
        }
        else curr2=curr2->next;
    }

    return result;
}


int main() {

    Node* head1=new Node(0);
    Node* curr1=head1;
    for(int i=1;i<10;i++){
        curr1->next=new Node(i);
        curr1=curr1->next;
    }


    Node* head2=new Node(5);
    Node* curr2=head2;
    for(int i=5;i<10;i++){
        curr2->next=new Node(i);
        curr2=curr2->next;
    }


    Node* newH=intersection(head1,head2);

    
    Node* temp=newH;

    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    
}