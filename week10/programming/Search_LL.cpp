#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data=data;
    }
};

bool check(Node* h1,Node* h2){
    Node* c2=h2;

    bool flag=true;

    while(c2){
        Node* c1=h1;

        Node* temp=c2;

        while(temp && c1 && c1->data==temp->data){
            c1=c1->next;
            temp=temp->next;
        }

        if(c1==NULL) return true;
        c2=c2->next;

    }

    return false;

}

int main() {

    Node* head1=new Node(0);
    Node* curr1=head1;
    for(int i=1;i<10;i++){
        curr1->next=new Node(i);
        curr1=curr1->next;
    }


    Node* head2=new Node(4);
    Node* curr2=head2;
    for(int i=5;i<10;i++){
        curr2->next=new Node(i);
        curr2=curr2->next;
    }


    bool res=check(head1,head2);

    if(res) cout<<"YES";
    else cout<<"NO";

    
}