#include<iostream>
#include"stacktype.cpp"
using namespace std;

void printStack(StackType<int> st){
    StackType<int> temp;

    while(!st.IsEmpty()){
        temp.Push(st.Top());
        st.Pop();
    }

    while(!temp.IsEmpty()){
        st.Push(temp.Top());
        cout<<temp.Top()<<" ";
        temp.Pop();
    }
}

int main()
{
    StackType<int> s;
    cout<<s.IsEmpty()<<endl;
    int n;

    for(int i=0; i<4; i++){
        cin>>n;
        s.Push(n);
    }


    cout<<endl;
    cout<<s.IsEmpty()<<endl;
    cout<<s.IsFull()<<endl;

    printStack(s);

    cout<<endl;
    cin>>n;
    s.Push(n);
    cout<<s.IsFull()<<endl;

    cout<<endl;
    printStack(s);

    cout<<endl;
    s.Pop();
    s.Pop();

    cout<<endl;
    cout<<s.Top()<<endl;

    StackType<char> parentheses;

    string s1;
    cin>>s1;

    for(int i=0; i<s1.length(); i++){
        if(s1[i] == '('){
            parentheses.Push(s1[i]);
        }
        else{
            if(parentheses.IsEmpty()){
                cout<<"Unbalanced"<<endl;
                exit(0);
            }
            else{
                parentheses.Pop();
            }
        }
    }

    if(parentheses.IsEmpty()){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Unbalanced"<<endl;
    }
}
