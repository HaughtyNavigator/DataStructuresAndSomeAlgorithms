#include<iostream>
#include"quetype.cpp"
using namespace std;

void printQ(QueType<int>qt){
    QueType<int> temp;

    while(!qt.IsEmpty()){
        int value;
        qt.Dequeue(value);
        cout<<value<<" ";
        temp.Enqueue(value);
    }

    while(!temp.IsEmpty()){
        int value;
        temp.Dequeue(value);
        qt.Enqueue(value);
    }
}

int main()
{
    QueType<int> q;
    int n;
    cout<<q.IsEmpty()<<endl;

    for(int i=0; i<4; i++){
        cin>>n;
        q.Enqueue(n);
    }

    cout<<q.IsFull()<<endl;
    cout<<q.IsEmpty()<<endl;

    printQ(q);

    cin>>n;
    cout<<endl;
    q.Enqueue(n);
    printQ(q);

    cout<<endl;
    cout<<q.IsFull()<<endl;

    cin>>n;
    cout<<endl;

    if(q.IsFull()){
        cout<<"Queue Overflow"<<endl;
    }
    else{
        q.Enqueue(n);
    }

    q.Dequeue(n);
    q.Dequeue(n);
    printQ(q);
    cout<<endl;


    q.Dequeue(n);
    q.Dequeue(n);
    q.Dequeue(n);

    cout<<q.IsEmpty()<<endl;


    if(q.IsEmpty()){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        q.Dequeue(n);
    }

  QueType<string> binary;                      
    int n;
    string var;
    cin >> n;

    binary.Enqueue("1");                         

    while (n--) {                                
        binary.Dequeue(var);                     
        string s1 = var;
        cout << s1 << endl;

        string s2 = s1;
        binary.Enqueue(s1.append("0"));          
        binary.Enqueue(s2.append("1"));          
    }
}
