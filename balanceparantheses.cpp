#include<iostream>
using namespace std;

class Stack{

struct Node{
    Node *next;
    char info;
    //Creating a Node
};
private:
    Node *head;
    //Head pointer of the Node

public:
    void push(char c);
    void pop();
    bool isEmpty();
    Stack();
    //Required operations
};

Stack :: Stack(){
    head = NULL;
    //By default, set to NULL
}

void Stack :: push(char c){
    Node *temp = new Node();
    temp->info = c;
    temp->next = head;
    head = temp;
}

void Stack :: pop(){
    Node* temp;

    if(head == NULL){
        cout<<"Not Balanced"<<endl;//Because my list got called for pop being in empty state, I ended the code here.
        exit(0);

    }
    else {
        temp = head;
        head = head->next;
        delete temp;
    }
}


bool Stack :: isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
   Stack s;
   int size;
   cin>>size;
   char arr1[size];
   //char arr1[] = {'(',')','(',')',')'};
   //int size = sizeof(arr1)/sizeof(arr1[0]);

   for(int j=0; j<size; j++) {
       cin >> arr1[j];
   }



    for(int i=0; i<size; i++){
        cout<<arr1[i]<<" ";


         if(arr1[i] == '('){
              s.push(arr1[i]);
         }
         else{
             s.pop();
         }
    }
    cout<<endl;
    if(s.isEmpty()){
        cout<<"Balanced";
    }
    else{
        cout<<"Not Balanced";
    }
}
