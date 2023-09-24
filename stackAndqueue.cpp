#include<iostream>
using namespace std;
class StackType{
    struct NodeType{
        int data;
        NodeType *next;
    };
private:
    NodeType *topPtr;

public:
    StackType();
    void push(int x);
    void pop();
    int top();
    bool isEmpty();
    void display();
};

class QueueType{
    struct Node{
        int info;
        Node *next;
    };
private:
    Node *head;
    Node *tail;
public:
    QueueType();
    void enqueue(int x);
    void dequeue();
    void makeEmpty();
    bool isEmpty();
    void display();
};



QueueType ::QueueType(){
    head = NULL;
    tail = NULL;
}

void QueueType::enqueue(int x){
    Node *n = new Node;
    n->info = x;
    n-> next = NULL;

    if(tail == NULL){
        head = n;
    }
    else{
        tail->next = n;
    }
    tail = n;
}

void QueueType::dequeue(){
    Node *temp;
    temp = head;
    head = head->next;
    delete temp;
}

bool::QueueType::isEmpty(){
    return head == NULL;
}

void QueueType::display(){
    Node *n1;
    n1 = head;
    while(n1 != NULL){
        cout<<n1->info<<" ";
        n1 = n1->next;
    }
    cout<<endl;
}

StackType::StackType(){
    topPtr = NULL;
}

bool StackType::isEmpty(){
    return topPtr == NULL;
}

int StackType::top()
{
    if (isEmpty()){
        cout<<"Error"<<endl;
        return 0;
    }
    else{
        return topPtr->data;
    }
}

void StackType::push(int x){
    NodeType *location = new NodeType;
    location -> data = x;
    location -> next = topPtr;
    topPtr = location;
}

void StackType::pop(){
    if(isEmpty()){
        cout<<"Nothing to delete"<<endl;
    }
    else{
        NodeType *temp;
        temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}

void StackType::display(){
    NodeType *n;
    n = topPtr;
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}


int main()
{
    int x;
    StackType s;
    for(int i=0; i<5; i++){
        cin>>x;
        s.push(x);
    }

    s.display();
    s.pop();
    s.display();

    int y;
    QueueType q;
    for(int i=0; i<5; i++){
        cin>>y;
        q.enqueue(y);
    }

    q.display();
    q.dequeue();
    q.display();
}
